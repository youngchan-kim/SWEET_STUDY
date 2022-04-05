#include<stdio.h>
#include<Windows.h>

int Strlen(char* str)
{
	int i = 0;
	while(str[i] != NULL)
	{
		i++;
	}
	return i;
}

void main()
{
	char str[10];
	printf("문자열 입력 : ");
	scanf("%s", str);

	printf("%s문자열의 길이 : %d\n", str, Strlen(str));
	system("pause");
}
