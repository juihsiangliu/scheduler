#include "parser.h"


bool parser(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	if (!fp) {
		printf("ERROR: open file %s error\n", filename);
		return false;
	}

	fclose(fp);
	return true;
}
