#include <cstdio>
#include <cstdlib>

#include "parser.h"
#include "resource.h"


int main(int argc, const char* argv[])
{
    ResourceMgr resourceMgr;

	bool b = parser(argv[1], &resourceMgr);
	if (!b) {
		printf("ERROR: parser %s error\n", argv[1]);
	}

	return 0;
}
