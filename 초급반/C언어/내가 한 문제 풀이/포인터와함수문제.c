#include<stdio.h>

#define LIMIT 8

void ConvertToUppercase(char* StringInput)
{
	for (int i = 0; StringInput[i] != 0; i++)
	{

		if ((StringInput[i]) >= 'a' && (StringInput[i]) <= 'z')
			StringInput[i] -= 32;

	}
}

void Max(int unknown1, int unknown2, int* maxnum)
{
	if (unknown1 > unknown2)
		*maxnum = unknown1;
	else if (unknown1 < unknown2)
		*maxnum = unknown2;
}
void Accumulate(int* maxnum)
{
	int sum = 0;
	for (int i = 1; i <= *maxnum; i++)
		sum += i;
	*maxnum = sum;
}

void SortAscending(int* anynum)
{
	int i = 0, tmp = 0, min = 0;
	for (int j = 0; j < LIMIT; j++)
	{
		for (i = 0; i < LIMIT; i++)
		{
			if (i + 1 < LIMIT)
			{
				if (anynum[i] > anynum[i + 1])
				{
					tmp = anynum[i];
					anynum[i] = anynum[i + 1];
					anynum[i + 1] = tmp;
				}
			}
		}
	}
}

void RePrint(int anynum[])
{
	for (int i = 0; i < LIMIT; i++)
	{
		printf("%d ", anynum[i]);
	}
}
void main()
{
	char StringInput[100] = { 0 };
	printf("1. ���ڸ� �Է��Ͻÿ� : ");
	scanf("%s", StringInput);


	printf("�Լ� ȣ�� �� = %s\n", StringInput);
	ConvertToUppercase(StringInput);
	printf("�Լ� ȣ�� �� = %s\n", StringInput);

	int unknown1 = 0, unknown2 = 0, maxnum = 0;
	printf("2. �� ������ �Է��Ͻÿ� : ");
	scanf("%d %d", &unknown1, &unknown2);
	Max(unknown1, unknown2, &maxnum);
	printf("%d��(��) %d �� ū ���� %d\n", unknown1, unknown2, maxnum);

	maxnum = 0;
	printf("3. ������ �Է��Ͻÿ� : ");
	scanf("%d", &maxnum);
	printf("1 ~ %d �� �� �� : ", maxnum);
	Accumulate(&maxnum);
	printf("%d\n", maxnum);

	int anynum[LIMIT] = { 0 };
	unknown1 = 0;
	printf("4. �������� ���� \n");
	for (int i = 0; i < LIMIT; i++)
	{
		printf("[%d]��° ���� �Է� : ", i);
		scanf("%d", &unknown1);
		anynum[i] = unknown1;
	}
	printf("������ : ");
	RePrint(anynum);
	printf("\n");
	SortAscending(anynum);
	printf("������ : ");
	RePrint(anynum);
}
