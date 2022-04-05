#include<stdio.h>
void main()
{
	char buf[40];
	int age = 20;
	char Name[10] = "최정호";
	sprintf(buf, "%s님의 나이는 %d살 입니다.", Name, age);
	printf("%s", buf);
}//스트링 포멧팅 과정 
//게임에서는 스토리중 내용중 유저의 아이디가 나올때 유저의 아이디만 바뀐다. 이 상황을 만드는 방법이다.