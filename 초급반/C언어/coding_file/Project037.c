#include<stdio.h>

void main()
{
	FILE* f = fopen("Test.txt", "a");
	int Num = 123;
	fprintf(f, "�߰���� %d", Num);
	fclose(f);
}