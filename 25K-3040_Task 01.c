#include<stdio.h>
int sum(n)
{
	if(n/10 < 1)
	{
		return n;
	}
	else
	{
		return n%10 + sum(n/10);
	}
}

int main()
{
	int n;
	printf("Enter a Number: ");
	scanf("%d", &n);
	printf("The Sum of the Number is: %d\n", sum(n));
	return 0;
}
