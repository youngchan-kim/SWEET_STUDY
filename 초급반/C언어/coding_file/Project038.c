#include<stdio.h>

void main()
{
	FILE* f = fopen("Test.txt", "w");
	int Num;
	fprintf(f, "1 2 3 4");
	fclose(f);
	f = fopen("Test.txt", "r");
	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	else
	{
		while (!feof(f))	// f(파일)e(엔드)of(오프) : 파일의 끝에 도착하면 참이된다.
		{
			fscanf(f, "%d", &Num);
			printf("%d", Num);
		}
		fclose(f);
	}
}
