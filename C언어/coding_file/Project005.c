#include<stdio.h>
void main()
{
	char buf[40];
	int age = 20;
	char Name[10] = "����ȣ";
	sprintf(buf, "%s���� ���̴� %d�� �Դϴ�.", Name, age);
	printf("%s", buf);
}//��Ʈ�� ������ ���� 
//���ӿ����� ���丮�� ������ ������ ���̵� ���ö� ������ ���̵� �ٲ��. �� ��Ȳ�� ����� ����̴�.