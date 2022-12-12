#include<stdio.h>
#include <string.h>

// 
void string_count(char *a)
{
	//영어철자 갯수
	//int cnt[26] = {0};
	
	//문장의 길이
	int str_len = strlen(a);
	int count = 0;

	//단어가 끝나는 지점 체크
	
	//카운트
	for(int i = 0; i < str_len; i++)
	{
		if (a[i] != ' ')
		{
			if (a[i + 1] == ' ' || a[i + 1] == NULL)
				count+=1;
		}
		if (a[i] == NULL)
			break;
	}
	printf("%d", count);
}



int main()
{
	char a[1000001] = "";
	scanf("%[^\n]s", a);
	string_count(a);
	return 0;
}