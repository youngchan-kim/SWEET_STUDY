#include<stdio.h>

#define TRUE 1
#define FALSE 0

void ReadText()
{
	char buf[256];
	FILE* f = fopen("Alice.txt", "r");

	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	else
	{
		while (!feof(f))
		{
			fgets(buf, sizeof(buf), f);
			printf("%s\n", buf);
		}
	}
	fclose(f);
}

void Compare(char* input, char* buf, int* count)
{
	int jmax = 0;
	for (int j = 0; buf[j] != 0; j++)
	{
		int flag = TRUE, i = 0;
		jmax = j+1;
		
		if (buf[j] == input[i])
		{
			for (i = 1; input[i] != 0; i++)
			{
				j++;
				if (input[i] != buf[j])
				{
					flag = FALSE;
					j = jmax;
					break;
				}

			}
			if (flag == TRUE)
			{
				*count += 1;
			}
		}
	}
}

int WordCount(char* input)
{
	int count = 0;
	char buf[256];
	FILE* f = fopen("Alice.txt", "r");

	if (f == NULL)
		printf("해당 이름의 파일이 없습니다.");
	else
	{
		while (!feof(f))
		{

			fgets(buf, sizeof(buf), f);
			Compare(input, buf, &count);


		}
	}
	fclose(f);
	return count;
}

void main()
{
	char input[20];


	ReadText();

	printf("Check Word Input :");
	scanf("%s", input);
	printf("KMP Check %s Count : %d", input, WordCount(input));

}