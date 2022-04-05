#include<stdio.h>

void main()
{
	FILE* f = fopen("Test.txt", "a");
	int Num = 123;
	fprintf(f, "추가모드 %d", Num);
	fclose(f);
}