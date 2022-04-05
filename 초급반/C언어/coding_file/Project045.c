#include<stdio.h>
#include<string.h>

void main()
{
	char str1[10] = "string!!";
	char str2[10] = "string";

	printf("%s == %s : %d\n", str1, str2, strcmp(str1, str2));
	printf("%s == %s : %d\n", "abc", "abc", strcmp("abc", "abc"));
	printf("%s == %s : %d\n", "abc", "def", strcmp("abc", "def"));
}