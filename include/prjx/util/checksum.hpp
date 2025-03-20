#include <cstdlib>
#include <cstdio>
#include <filesystem>

#include <prjx/math/scalar.hpp>

namespace prjx::checksum
{
	using namespace prjx::math;

	inline constexpr u64 read_bytes(u8*& buf, u64& cnt)
	{
		u64 ret = -1;
		/* extract 3 bytes */
		if(cnt > 2)
		{
			ret = buf[2] << 16 | buf[1] << 8 | buf[0] << 0; buf+=3; cnt-=3;
		}
		/* extract remaining tail */
		else if(cnt > 0)
		{
			ret = cnt == 2 ? buf[1] << 8 : 0; ret |= buf[0]; buf+=cnt; cnt=0;
		}
		return ret;
	}
	constexpr i64 compute_block( u8 buf[4096], u64 len )
	{
		i64 ret = 0;

		for(u32 shl = 0; len > 0; shl+=7, shl&=0x1F)
			ret += read_bytes(buf, len) << shl;

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

