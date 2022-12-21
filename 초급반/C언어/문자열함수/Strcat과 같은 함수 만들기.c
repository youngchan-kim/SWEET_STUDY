#include<stdio.h>
#include<string.h>

void main()
{
	char str[10] = "Hello";
	printf("%s\n", str);
	strcat(str, "^^");
	printf("%s\n", str);
}