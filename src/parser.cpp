#include "parser.h"

const static int bufSize = 4096;
static bool parseResourcePart(char* buf);
static bool parseTaskPart(char* buf);

bool parser(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	if (!fp) {
		printf("ERROR: open file %s error\n", filename);
		return false;
	}

	char buf[bufSize];
	enum stage_e {init, resource, task};
    enum stage_e stage = init;
	
	while(1) {
		memset(buf, 0, bufSize * sizeof(char));
		char* ch = fgets(buf, bufSize, fp);
		if (ch == NULL) {
			break;
		}
		buf[strlen(buf)-1] = 0;

		if (strcmp(buf, "#resource_list") == 0) {
			stage = resource;
		}
		else if (strcmp(buf, "#task_list") == 0) {
			stage = task;
		}

		if (stage == resource) {
			parseResourcePart(buf);
		}
		else if (stage == task) {
			parseTaskPart(buf);
		}
		else {
			printf("init %s\n", buf);
		}
	}

	fclose(fp);
	return true;
}

bool parseResourcePart(char* buf)
{
	printf("resource %s\n", buf);
	return true;
}

bool parseTaskPart(char* buf)
{
	printf("task: %s\n", buf);
	return true;
}
