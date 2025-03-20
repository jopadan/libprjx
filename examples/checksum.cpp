#include <iostream>
#include <getopt.h>
#include <prjx/util/checksum.hpp>

using namespace std::filesystem;
using namespace prjx;
using namespace prjx::math;

static bool recursive = false;

i64 prjxsum(path src);
void print_usage(const char* program_file);
void config_args(int argc, char** argv);

int main(int argc, char** argv)
{
	config_args(argc, argv);

	for(int i = optind; i < argc; i++)
		prjxsum(argv[i]);

	exit(EXIT_SUCCESS);
}

i64 prjxsum(path src)
{
	src = canonical(src);
	if(exists(src))
	{
		if(!is_directory(src))
		{
			i64 sum = checksum::verify(src);
			checksum::print(sum, src);
			return sum;
		}
		else if(is_directory(src))
		{
			directory_iterator dir_iter(src);
			while(dir_iter != end(dir_iter))
			{
				const directory_entry& dir_entry = *dir_iter++;
				if(!is_directory(dir_entry) || recursive)
					prjxsum(dir_entry.path());
			}
		}
		else
			std::cerr << "prjxsum: cannot access " << src << ": Not a file or directory" << std::endl;	
	}
	else
		std::cerr << "prjxsum: cannot access " << src << ": No such file or directory" << std::endl;	
	return -1;
}

void print_usage(const char* program_file)
{
	std::cerr << "Usage: " << program_file << " [-r] [FILE]..." << std::endl << "Calculate Forsaken ProjectX style checksums for FILEs [recursivly] (the current directory by default)." << std::endl;
}

void config_args(int argc, char** argv)
{
	if(argc < 2)
	{
		print_usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	int opt;
	int option_index;

	static struct option long_options[] = {
		{ "recursive", no_argument, 0, 'r' },
		{ "file", required_argument, 0, 0 },
		{ NULL, 0, NULL, 0 },
	};

	while((opt = getopt_long(argc, argv, "rc:", long_options, &option_index)) != -1)
	{
		switch(opt)
		{
			case 'r':
				recursive = true;
				break;
			default:
				print_usage(argv[0]);
				exit(EXIT_FAILURE);
				break;
		}
	}
}
