#include <stdio.h>
int main()
{
    FILE *file;
    file = fopen("data.txt", "w");
    if(file == NULL)
	{
        printf("Could Not Open File\n");
        return 1;
    }
    fclose(file);
    printf("All Contents Of \"data.txt\" Have Been Deleted\n");
    file = fopen("data.txt", "r");
    if(file == NULL)
	{
        printf("Could Not Open File for Reading\n");
        return 1;
    }
    int ch = fgetc(file);
    if(ch == EOF)
	{
        printf("File is Empty\n");
    }
	else
	{
        printf("File is Not Empty\n");
    }
    fclose(file);
    return 0;
}

