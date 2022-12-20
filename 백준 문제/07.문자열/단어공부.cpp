#include<stdio.h>
#include <string.h>

//문자열 함수명은 QR_Code

// 문자를 입력 받고 그중 가장 많이 입력된 한글자를 출력한다.
// 가장 많은 글자가 다수 이면 ?
// 한글자만 있으면 1글자만 출력
// 출력 시 대문자로 출력


//문자비교
//문자 별 카운트

void string_count(char *a)
{
	int max = 0, max_str=0;
	int cnt[26] = {0};
	int str_len = strlen(a);
	int count = 0;
	int strnum = 0;
	//별들의 카운트
	for (int j = 0; j < str_len; j++)
	{
		for (int i = 'A'; i <= 'Z'; i++)
		{
			if (i == a[j])
			{
				cnt[i - 'A']++;
				break;
			}
		}
	}
	for (int j = 0; j < str_len; j++)
	{
		for (int i = 'a'; i <= 'z'; i++)
		{
			if (i == a[j])
			{
				cnt[i - 'a'] += 1;
				break;
			}
		}
	}

	//별들의 카운트 비교
	for (int i = 0; i < 25-1; i++)
	{
		for (int j = i+1; j < 26; j++)
		{
			if (cnt[i] >= cnt[j])
			{
				max = cnt[i];
				max_str = i;
			}
			else if (cnt[i] < cnt[j])
			{
				//배열 j가 더큼
				max = cnt[j];
				max_str = j;
				i = j;
			}
		}
		break;
	}

	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] == max)
			count++;
	}

	if (count > 1) strnum = '?';
		
	else strnum = (max_str + 'A');
		
	printf("%s", &strnum);

}



int main()
{
	char a[1000000] = { NULL };

	scanf("%s", &a);
	string_count(a);
	return 0;

}