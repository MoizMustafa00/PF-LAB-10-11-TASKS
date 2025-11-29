#include<stdio.h>
#include<string.h>
int countVowel(char s[], int n)
{
	int vowel = 0;
	if(s[n] == '\0')
	{
		return 0;
	}
	else
	{
		if(s[n] == 'a' || s[n] == 'A'
		|| s[n] == 'e' || s[n] == 'E'
		|| s[n] == 'i' || s[n] == 'I'
		|| s[n] == 'o' || s[n] == 'O'
		|| s[n] == 'u' || s[n] == 'U')
		{
			vowel++;
		}
		return vowel + countVowel(s, n+1);
	}	
}

int main()
{
	char str[50];
	printf("Enter the String: ");
	fgets(str, sizeof(str), stdin);
	str[strcspn(str, "\n")] = '\0';
	int len = 0;
	printf("Number of Vowels in the Given String are: %d", countVowel(str, len));
	return 0;
}
