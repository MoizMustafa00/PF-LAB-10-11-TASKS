#include<stdio.h>
#include<string.h>
char search(char arr[][20], int index, char input[], int size)
{
	if(index == size)
	{
		return 'n';
	}
	if(strcmp(arr[index], input) == 0)
	{
		return 'y';
	}
	else
	{
		return search(arr, index+1, input, size);
	}
}

int main()
{
	char arr[5][20] = {"Recursion", "Array", "Function", "Structure", "Pointer"};
	char input[20];
	char result;
	printf("Enter String to Check in String Array: ");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';
	result = search(arr, 0, input, 5);
	if(result == 'y')
	{
		printf("Found\n");
	}
	else
	{
		printf("Not Found\n");
	}
	return 0;
}
