#include <cstdlib>
#include <cstdio>
#include <endian.h>
#include <filesystem>

#include <prjx/math/scalar.hpp>

namespace prjx::checksum
{
	using namespace prjx::math;

	constexpr i64 compute_block( u8 buf[4096], u64 len, u32 shl = 0)
	{
		i64 ret = 0;

		for(; len>=((1<<2)-1); buf+=(1<<2)-1, len-=(1<<2)-1, shl=(shl + ((1<<3)-1)) % (1<<5))
			ret += ((i64)le32toh(*(u32*)buf & 0x00FFFFFF)) << shl;
		if(len > 0)
			ret += ((i64)le16toh(*(u16*)buf & (len == 2 ? 0xFFFF : 0x00FF))) << shl;
		return ret;  
	}
 
	constexpr i64 verify( u8* buf, u64 size )
	{
		i64 data = 0;

		if(buf != NULL && size > 0)
		{
			for(u64 len = 0; size > 0; buf+=len, size-=len)
			{
				len = std::min<u64>(size, 4096lu);
				data += compute_block(buf, len);
			}
			return data;
		}
		return -1;
	}

	constexpr i64 verify( std::filesystem::path fname )
	{
		FILE *f      = NULL;
		i64 data     =    0;
		u64 len      =    0;
		u8 buf[4096] = {  };

		if(!fname.empty() &&
		   std::filesystem::exists(fname) &&
		   std::filesystem::file_size(fname) > 0 &&
		   (f = fopen( fname.c_str(), "rb" )))
		{
			while( !feof(f) && !ferror(f) )
			{
				len = fread( (void *) buf, 1, sizeof( buf ), f );
				data += compute_block(buf, len);
			}
			fclose( f );
			return data;
		}
		return -1;
	}

	void print(i64 sum, std::filesystem::path filename, bool binary = true, FILE* stream = stdout)
	{
		fprintf(stream, "%016lx %c%s\n", sum, binary ? '*' : ' ', filename.c_str());
	}
};

