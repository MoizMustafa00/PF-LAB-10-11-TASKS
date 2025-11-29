#include <stdio.h>

void mergeFiles(const char *file1, const char *file2, const char *outputFile)
{
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    FILE *out = fopen(outputFile, "w");
    if(f1 == NULL || f2 == NULL || out == NULL)
	{
        printf("Error Opening Files.\n");
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        if (out) fclose(out);
        return;
    }
    char ch;
    while((ch = fgetc(f1)) != EOF)
	{
        fputc(ch, out);
    }
    while((ch = fgetc(f2)) != EOF)
	{
        fputc(ch, out);
    }
    fclose(f1);
    fclose(f2);
    fclose(out);
    printf("Files Merged Successfully into %s\n", outputFile);
}

int main()
{
    char file1[100], file2[100], outputFile[100];
    printf("Enter First Filename: ");
    scanf("%s", file1);
    printf("Enter Second Filename: ");
    scanf("%s", file2);
    printf("Enter Output Filename: ");
    scanf("%s", outputFile);
    mergeFiles(file1, file2, outputFile);
    return 0;
}
