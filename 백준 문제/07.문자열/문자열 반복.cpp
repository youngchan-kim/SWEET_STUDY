#include<stdio.h>
#include <string.h>

//���ڿ� �Լ����� QR_Code
//���ڿ��� alphanumeric
//���ڴ� 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./:
// �����ڸ� R�� �ݺ��Ͽ� �� ���ڿ� p�� ���� �� ����ϴ� ���α׷�

// ���̽��� ������ üũ
int Test_case(int a)
{
	if (a <= 0) { return -1; }
	else if (a >= 1001) { return -1; }
	return a;
}

// ��� �ݺ��ϴ� �� üũ
int Count(int a)
{
	if (a <= 0) { return -1; }
	else if (a >= 9) { return -1; }
	return a;
}

//���ڿ��� ���� üũ
int S_len(char *a)
{
	if (strlen(a) < 1){ return -1; }
	else if (strlen(a) > 20){ return -1; }
	return strlen(a);
}
//���ڸ� ���ڿ��� ���̸�ŭ �ݺ� ��
void S_repeat(char *a, int R, int s_len)
{
	char b[256];
	char c[256] = { NULL };
	int i = 0, j = 0;
	strcpy(b, a);
	
	while (b[i] != NULL)
	{
		int k = 0;
		while (k < R)
		{
			c[j] = b[i];
			j++;
			k++;
		}
		i++;

	}
	printf("%s \n", c);
}

int main()
{
	int R, T, s_len;
	int T_count = 1;
	char a[256], b[256];

	scanf("%d", &T);
	if (Test_case(T) != -1)
	{
		while (T_count <=  T)
		{
			scanf("%d  %s", &R, a);
			if (Count(R) != -1)
			{
				s_len = S_len(a);
				if (s_len != -1)
				{
					S_repeat(a, R, s_len);
				}
			}
			T_count++;
		}
	}
	return 0;

}