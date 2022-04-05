#include<list> //Linked Type List : ���� ���� ��Ű�°� �ٽ�
#include<vector> //Array Type List : ���������� ���� �ϴ°�

//list�� ����: �������� ����� ������ ������. �����ϱ� ������, �����ο�
//list�� ���� : Ư�� ������ ���� �ӵ��� ������.


//vector�� ���� : Ư�� ������ ���� �ӵ��� ������. ������ ���� �ּҰ� ������ �����ؼ� ����
//vector�� ���� : Ư�� �������� ����� ������ ������. �ƿ� �� �����ϰ� ���� �������Ѵ�.
//list : ����ϰ� ���� �ٲ�� ���
//vector : ���� ������ �ʴ� ���

void PrintList(std::list<int> iList)
{
	for (std::list<int>::iterator iter = iList.begin(); iter != iList.end(); iter++)
		printf("%d ", *iter);
	printf("\n");
}

std::list<int>::iterator Search(std::list<int>* iList, int SearchData)
{
	for (std::list<int>::iterator iter = iList->begin(); iter != iList->end(); iter++)
	{
		if (*iter == SearchData)
			return iter;
	}
	return iList->end();
}

void SearchData(std::list<int>* iList, int Data)
{
	std::list<int>::iterator findIter = Search(iList, Data);
	if (findIter != iList->end())
		printf("Data %d Found!\n", Data);
	else
		printf("Data %d Not Found!\n", Data);
}

void AddData(std::list<int>* iList, int SearchDate, int Data)
{
	std::list<int>::iterator findIter = Search(iList, SearchDate);
	if (findIter != iList->end())
		iList->insert(findIter, Data);
	else
		printf("Data %d Not Found!\n", Data);
}

void DeleteData(std::list<int>* iList,  int Data)
{
	std::list<int>::iterator findIter = Search(iList, Data);
	if (findIter != iList->end())
		iList->erase(findIter);
	else
		printf("Data %d Not Found!\n", Data);
}
void main()
{
	std::list<int> iList;
	for(int i = 1; i <= 10; i ++)
		iList.push_back(i);

	iList.push_front(11);
	PrintList(iList);

	SearchData(&iList, 5);
	SearchData(&iList, 25);
	AddData(&iList, 5, 25);
	PrintList(iList);

	iList.pop_back();
	PrintList(iList);
	iList.pop_front();
	PrintList(iList);
	DeleteData(&iList, 25);
	PrintList(iList);


	//iList.clear();//��ü ����
	//iList.remove();//�����͸� �������� ����
	//iList.sort();//��������
	//iList.reverse();//������ ����
}