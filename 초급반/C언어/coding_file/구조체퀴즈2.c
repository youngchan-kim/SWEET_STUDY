#include<stdio.h>
#include<string.h>

void Strcpy(char* My_Name, char* Name)
{
	int i = 0;
	for (i = 0; My_Name[i] != 0; i++)
	{
		Name[i] = My_Name[i];
	}
	Name[i] = NULL;
}

void main()
{
	char Name[10];
	char My_Name[10] = "JungHo";

	Strcpy(My_Name, Name);
	printf("Name : %s\n", Name);
	printf("My_Name : %s\n", My_Name);
}