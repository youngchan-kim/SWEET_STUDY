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
	printf("���ڿ� �Է� : ");
	scanf("%s", str);

	printf("%s���ڿ��� ���� : %d\n", str, Strlen(str));
	system("pause");
}
