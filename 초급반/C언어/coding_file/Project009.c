#include<stdio.h>
#include<Windows.h>

void main()
{
	printf("��ȭ �Ŵ� �� ��");
	for (int i = 0; i < 3; i++)
	{
		Sleep(1000);
		printf(".");
	}
	Sleep(1000);
}