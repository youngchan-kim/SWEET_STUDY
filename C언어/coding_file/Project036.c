#include<stdio.h>

void main()
{
	FILE* f = fopen("Test.txt", "w");
	int Num = 123;
	fprintf(f, "���� ���� ��� %d", Num);
	fclose(f);
}
