#include<stdio.h>
#include <string.h>

//문자열 함수명은 QR_Code
//문자열은 alphanumeric
//문자는 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./:
// 각문자를 R번 반복하여 새 문자열 p를 만든 후 출력하는 프로그램

// 케이스의 갯수를 체크
int Test_case(int a)
{
	if (a <= 0) { return -1; }
	else if (a >= 1001) { return -1; }
	return a;
}

// 몇번 반복하는 지 체크
int Count(int a)
{
	if (a <= 0) { return -1; }
	else if (a >= 9) { return -1; }
	return a;
}

//문자열의 길이 체크
int S_len(char *a)
{
	if (strlen(a) < 1){ return -1; }
	else if (strlen(a) > 20){ return -1; }
	return strlen(a);
}
//문자를 문자열의 길이만큼 반복 및
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