#include<stdio.h>
#include<string.h>

int Strcmp(char* str1, char* str2)
{
	int index = 0;

	for (index = 0; str1[index] != 0 || str2[index] != 0; index++)
	{
		if (str1[index] > str2[index])
		{
			return 1;
		}
		else if (str1[index] < str2[index])
		{
			return -1;
		}
	}
	if (str1[index] == NULL && str2[index] == NULL)
		return 0;
}
void main()
{
	char str1[10];
	char str2[10];
	printf("(1~9�ڸ��� ���� ���ڿ� 1���� �Է� :");
	scanf("%s", str1);
	printf("(1~9�ڸ��� ���� ���ڿ� 2���� �Է� :");
	scanf("%s", str2);

	printf("%s == %s : %d\n", str1, str2, Strcmp(str1, str2));
}