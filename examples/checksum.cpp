#include <prjx/util/checksum.hpp>

using namespace prjx;
using namespace prjx::math;

u8* buf = NULL;
void clean()
{
	if(buf != NULL)
		free(buf);
	buf = NULL;
}

int main(int argc, char** argv)
{
	while(argc > 1 && std::filesystem::exists(argv[1]))
	{
		/* print checksum of file */
		checksum::print(checksum::verify(argv[1]));

		u64 len  = std::filesystem::file_size(argv[1]);
		u64 read = 0;

		if(len > 0)
		{
			FILE* fp = fopen(argv[1], "rb");
			u8* buf = (u8*)calloc(1, len);
			atexit(clean);
			u64 read = fread(buf, 1, len, fp);
			fclose(fp);

			/* print checksum of data in buf of len bytes */
			if(len == read)
			{
				checksum::print(checksum::verify(buf, len));
				exit(EXIT_SUCCESS);
			}
		}
	}
	printf("Usage: %s FILE\n", argv[0]);
	exit(EXIT_FAILURE);
}
