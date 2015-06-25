#include <cstdio>
#include <cstdlib>

#include "parser.h"


int main(int argc, const char* argv[])
{
	bool b = parser(argv[1]);
	if (!b) {
		printf("ERROR: parser %s error\n", argv[1]);
	}

	return 0;
}
