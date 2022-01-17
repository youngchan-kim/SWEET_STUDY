#include<stdio.h>
#include<string.h>

void main()
{
	char Name1[10] = "ABC";
	char Name2[10] = "BCA";
	char Name3[10] = "ABC";

	printf("Name1 == Name2: %d\n", strcmp(Name1, Name2));
	printf("Name1 == Name3: %d\n", strcmp(Name1, Name3));
	printf("Name2 == Name3: %d\n", strcmp(Name2, Name3));

}