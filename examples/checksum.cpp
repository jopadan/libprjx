#include <prjx/util/checksum.hpp>

using namespace prjx;
using namespace prjx::math;

int main(int argc, char** argv)
{
	if(argc <= 1)
	{
		printf("Usage: %s [FILE]...\nCalculate Forsaken ProjectX style checksums for FILEs (the current directory by default).\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	i64 sum[2] = { -1, -1 };
	for(int i = 1; i < argc && std::filesystem::exists(argv[i]); i++)
	{
		/* print checksum of file */
		sum[0] = checksum::verify(argv[i]);

		u64 len  = std::filesystem::file_size(argv[i]);
		u64 read = 0;

		if(len > 0)
		{
			FILE* fp = fopen(argv[i], "rb");
			u8* buf = (u8*)calloc(1, len);
			u64 read = fread(buf, 1, len, fp);
			fclose(fp);

			/* print checksum of data in buf of len bytes */
			if(len == read)
				sum[1] = checksum::verify(buf, len);
			free(buf);
			if(sum[0] != sum[1])
				fprintf(stderr, "[ERR] file and buffer checksum don't match!\n");
			checksum::print(sum[0], argv[i]);
		}
	}
	exit(EXIT_SUCCESS);
}
