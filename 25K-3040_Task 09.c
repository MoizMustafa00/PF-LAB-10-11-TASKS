#include<stdio.h>
#include<string.h>
int linearSearch(char arr[], int size, char target, int index)
{
	if(index == size)
	{
		return -1;
	}
	else if(arr[index] == target)
	{
		return index;	
	}
	else
	{
		return linearSearch(arr, size, target, index+1);
	}
}

int main()
{
	char arr[50];
	int index = 0;
	printf("Enter the String: ");
	fgets(arr, sizeof(arr), stdin);
	arr[strcspn(arr, "\n")] = '\0';
	int size = strlen(arr);
	char target;
	printf("Enter the Target Element to Search For: ");
	scanf(" %c", &target);
	int result = linearSearch(arr, size, target, index);
	if(result == -1)
	{
		printf("Element Not Found\n");
	}
	else
	{
		printf("Target Element Found at Index %d\n", result);
	}
	return 0;
}
