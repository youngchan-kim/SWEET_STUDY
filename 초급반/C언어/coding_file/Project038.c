#include<stdio.h>

void main()
{
	FILE* f = fopen("Test.txt", "w");
	int Num;
	fprintf(f, "1 2 3 4");
	fclose(f);
	f = fopen("Test.txt", "r");
	if (f == NULL)
		printf("�ش� �̸��� ������ �����ϴ�.");
	else
	{
		while (!feof(f))	// f(����)e(����)of(����) : ������ ���� �����ϸ� ���̵ȴ�.
		{
			fscanf(f, "%d", &Num);
			printf("%d", Num);
		}
		fclose(f);
	}
}
