#include <cstdlib>
#include <cstdio>
#include <filesystem>

#include <prjx/math/scalar.hpp>

namespace prjx::checksum
{
	using namespace prjx::math;

	i64 compute_block( u8 buf[4096], u64 size )
	{
		i64   data   = 0;
		u64 current  = 0;
		u32    shift = 0;

		for ( current = shift = 0; current < size; current += 3, shift = (shift + 7) & 0x1F)
			data += ((i64)((*(u32*)&buf[current]) & ((1 << (8 * ((size - current < 3 ? size - current : 3))))-1))) << shift;

		return data;
	}

	i64 verify( u8* buf, u64 size )
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

	i64 verify( std::filesystem::path fname )
	{
		FILE *f        = NULL;
		i64 data       =    0;
		u64 len        =    0;
		u8 buf[ 4096 ] = {  };

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

	void print(i64 sum, FILE* stream = stdout)
	{
		fprintf(stream, "0x%016lX\n", sum);
	}
};

