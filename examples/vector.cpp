#include <cstdlib>
#include <cstdio>
#include "vector.hpp"

int main(int argc, char** argv)
{
	vec::f32<2> a = {1,2};
	vec::f32<3, align::vector> b = {1,2,3};
	vec::f32<17> c = {1,2,3};
	vec::f32<32> d = {1,2,3};

	printf("%zu/%zu\n", alignof(a), sizeof(a));
	printf("%zu/%zu\n", alignof(b), sizeof(b));
	printf("%zu/%zu\n", alignof(c), sizeof(c));
	printf("%zu/%zu\n", alignof(d), sizeof(d));
	printf("%f %f %f %f\n", b.x(), b.y(), b.z(), b[3]);
	exit(EXIT_SUCCESS);
}
