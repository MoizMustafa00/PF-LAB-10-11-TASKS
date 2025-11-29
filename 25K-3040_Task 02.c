#include<stdio.h>
#include<string.h>
char reversed(char str[], int n)
{
	if(n < 0)
	{
		return;
	}
	else
	{
		printf("%c", str[n]);
		return reversed(str, n-1);
	}
}

int main()
{
	char str[50];
	printf("Enter the String: ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	int n = strlen(str);
	reversed(str, n-1);
	return 0;
}
