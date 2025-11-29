#include <stdio.h>
#include <time.h>
int main()
{
    FILE *file;
    time_t t;
    struct tm *tm_info;
    char timeStr[26];
    time(&t);
    tm_info = localtime(&t);
    strftime(timeStr, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    file = fopen("log.txt", "a");
    if(file == NULL)
	{
        printf("Unable to Open \"log.txt\" for Appending.\n");
        return 1;
    }
    fprintf(file, "%s\n", timeStr);
    fclose(file);
    printf("Program Execution Logged at: %s\n", timeStr);
    return 0;
}

