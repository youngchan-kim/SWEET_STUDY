#include<stdio.h>
#include <string.h>

//���ڿ� �Լ����� QR_Code

// ���ڸ� �Է� �ް� ���� ���� ���� �Էµ� �ѱ��ڸ� ����Ѵ�.
// ���� ���� ���ڰ� �ټ� �̸� ?
// �ѱ��ڸ� ������ 1���ڸ� ���
// ��� �� �빮�ڷ� ���


//���ں�
//���� �� ī��Ʈ

void string_count(char *a)
{
	int max = 0, max_str=0;
	int cnt[26] = {0};
	int str_len = strlen(a);
	int count = 0;
	int strnum = 0;
	//������ ī��Ʈ
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

	//������ ī��Ʈ ��
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
				//�迭 j�� ��ŭ
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