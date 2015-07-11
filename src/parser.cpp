#include "parser.h"
#include "task.h"

const static int bufSize = 4096;
static bool parseResourcePart(char* buf, bool& bSkip);
static bool parseTaskPart(char* buf, bool& bSkip);

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
    bool bSkip = false;

    while(1) {
        memset(buf, 0, bufSize * sizeof(char));
        char* ch = fgets(buf, bufSize, fp);
        if (ch == NULL) {
            break;
        }
        buf[strlen(buf)-1] = 0;

        if (strcmp(buf, "#resource_list") == 0) {
            stage = resource;
            bSkip = true;
            continue;
        }
        else if (strcmp(buf, "#task_list") == 0) {
            stage = task;
            bSkip = true;
            continue;
        }

        if (stage == resource) {
            parseResourcePart(buf, bSkip);
        }
        else if (stage == task) {
            parseTaskPart(buf, bSkip);
        }
        else {
            printf("init %s\n", buf);
        }
    }

	fclose(fp);
	return true;
}

bool parseResourcePart(char* buf, bool& bSkip)
{
    if (bSkip) {
        bSkip = false;
        return true;
    }

    char* pattern = strtok(buf, ",");
    char resourceName[1024];
    strcpy(resourceName, pattern);
	printf("resource %s\n", resourceName);

    int period[2];
    for (int i = 0; i < 2; i++) {
        pattern = strtok(NULL, ",");
        period[i] = atoi(pattern);
        printf("\t %d", period[i]);
    }
    printf("\n");

	return true;
}

bool parseTaskPart(char* buf, bool& bSkip)
{
    if (bSkip) {
        bSkip = false;
        return true;
    }

    char* pattern = strtok(buf, ",");
    int taskId = atoi(pattern);
	printf("taskId: %d\n", taskId);
    
    const int patternCnt = 9;
    char* charAry[patternCnt];
    
    for (int i = 0; i < patternCnt; i++) {
        charAry[i] = (char *) malloc(1024 * sizeof(char));
    }

    for (int i = 0; i < patternCnt; i++) {
    }
    
    for (int i = 0; i < patternCnt; i++) {
        free(charAry[i]);
    }

    return true;
}
