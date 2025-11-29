#include<stdio.h>
int main()
{
    FILE *file;
    char filename[100];
    char ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;
    printf("Enter the Filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("Could Not Open File %s\n", filename);
        return 1;
    }
    while((ch = fgetc(file)) != EOF)
	{
        characters++;
        if(ch == '\n')
		{
            lines++;
        }
        if(ch == ' ' || ch == '\t' || ch == '\n')
		{
            if(inWord)
			{
                words++;
                inWord = 0;
            }
        }
		else
		{
            inWord = 1;
        }
    }
    if(inWord)
	{
        words++;
    }
    fclose(file);
    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
    return 0;
}
