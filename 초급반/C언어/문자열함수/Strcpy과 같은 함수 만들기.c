#include<stdio.h>
#include<string.h>

void Strcpy(char* My_Name, char* Name)
{
	int i = 0;
	for (i = 0; My_Name[i] != 0; i++)
	{
		Name[i] = My_Name[i];
	}
<<<<<<< Updated upstream:문자열함수/Strcpy과 같은 함수 만들기.c
	Name[i] = NULL;
=======
	Name[i + 1] = NULL;
>>>>>>> Stashed changes:Strcpy과 같은 함수 만들기.c
}

void main()
{
<<<<<<< Updated upstream:문자열함수/Strcpy과 같은 함수 만들기.c
	char Name[10];
	char My_Name[10] = "JungHo";
=======
	char Name[10] = { 0 };
	char My_Name[10] = "JungHo123";
>>>>>>> Stashed changes:Strcpy과 같은 함수 만들기.c

	Strcpy(My_Name, Name);
	printf("Name : %s\n", Name);
	printf("My_Name : %s\n", My_Name);
}