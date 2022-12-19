#include<stdio.h>

void main()
{
	FILE* f = fopen("Test.txt", "w");
	int Num = 123;
	fprintf(f, "덮어 쓰기 모드 %d", Num);
	fclose(f);
}
