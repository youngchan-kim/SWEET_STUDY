#include<stdio.h>

void ConvertToUppercase(char* str)
{
	if ((*str) >= 'a' && (*str) <= 'z')
		(*str) -= 32;
}

void main()
{
	char string[] = "string";
	printf("�Լ� ȣ�� �� = %s\n", string);
	ConvertToUppercase(string);
	printf("�Լ� ȣ�� �� = %s\n", string);
}