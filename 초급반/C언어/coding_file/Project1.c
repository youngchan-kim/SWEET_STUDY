#include<stdio.h>
#define Num 10
#define True 1


void main()
{
	int arr[Num] = {10, 17, 3, 9, 37, 10, 8, 9, 13, 21};



	/*printf("1�� ����\n");
	for (int i = 0; i < Num; i++)
	{
		printf("%d", arr[i]);
		if (i != Num-1)
			printf(",");
		else
			break;
	}
	printf("\n");


	printf("2�� ����\n");
	printf("invert_Arr : ");
	for (int j = Num-1; j >= 0; j--)
	{
		printf("%d", arr[j]);
		if (j != 0)
			printf(",");
		else
			break;
	}
	printf("\n");

	printf("Arr : ");
	for (int i = 0; i < Num; i++)
	{
		printf("%d", arr[i]);
		if (i != Num - 1)
			printf(",");
		else
			break;
	}
	printf("\n");

	printf("3�� ����\n");
	int sum = 0;
	printf("Ȧ�� ��° ���� : ");
	for (int i = 1; i < Num; i+=2)
	{
		printf("%d", arr[i]);
		sum += arr[i];
		if (i != Num - 1)
			printf(",");
		else
			break;
	}
	printf("\n");

	printf("Ȧ�� ��° ���� : ");
	printf("%d\n", sum);

	sum = 0;
	printf("¦�� ��° ���� : ");
	for (int i = 0; i < Num; i+=2)
	{
		printf("%d", arr[i]);
		sum += arr[i];
		if (i != Num - 2)
			printf(",");
		else
			break;
	}
	printf("\n");
	printf("¦�� ��° ���� : ");
	printf("%d\n", sum);
	*/

	printf("4�� ����\n");
	printf("Arr : ");
	for (int i = 0; i < Num; i++)
	{
		printf("%d", arr[i]);
		if (i != Num - 1)
			printf(",");
		else
			break;
	}
	printf("\n");

	printf("Sort_Arr : ");

	int temp[1] = { 0 };
	int i;

	for (int i = 0; i < Num; i++)
	{
		if (arr[i + 1] != arr[Num - 1])
		{
			if (arr[i] <= arr[i + 1])
			{
				temp[0] = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp[0];
			}
			printf("%d", arr[i]);
		}
		else
		{
			break;
		}
		//else if (arr[i] > arr[i + 1])
		//{

		//}
	}
}