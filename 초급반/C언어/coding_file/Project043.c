#include<stdio.h>
#include<string.h>

void main()
{
	char Name[10];
	char My_Name[10] = "JungHo";

	strcpy(Name, My_Name);
	printf("Name : %s\n", Name);
	printf("My_Name : %s\n", My_Name);
}