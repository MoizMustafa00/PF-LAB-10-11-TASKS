#include<stdio.h>
#include<string.h>
char isPalindrome(char arr[], int left, int right)
{
	if(left >= right)
	{
		return 'y';
	}
	else if(arr[left] == arr[right])
	{
		return isPalindrome(arr, left+1, right-1);
	}
	else
	{
		return 'n';
	}
}

int main()
{
	char arr[5][20];
	printf("Enter 5 Strings\n");
	int i;
	for(i=0; i<5; i++)
	{
		printf("String %d: ", i+1);
		fgets(arr[i], sizeof(arr[i]), stdin);
		arr[i][strcspn(arr[i], "\n")] = '\0';
		int right = strlen(arr[i]) - 1;
		int left = 0;
		char result = isPalindrome(arr[i], left, right);
		if(result == 'n')
		{
			printf("String %d = Not Palindrome\n", i+1);
		}
		else
		{
			printf("String %d = Palindrome\n", i+1);
		}
	}
	return 0;
}
