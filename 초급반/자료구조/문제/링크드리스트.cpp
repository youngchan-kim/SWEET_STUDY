#include<list> //Linked Type List : 직접 연결 시키는것 핵심
#include<vector> //Array Type List : 연속적으로 나열 하는것

//list의 장점: 데이터의 저장과 삭제가 빠르다. 연결하기 쉬워서, 자유로움
//list의 단점 : 특정 데이터 접근 속도가 느리다.


//vector의 장점 : 특정 데이터 접근 속도가 빠르다. 연산을 통한 주소가 접근이 가능해서 빠름
//vector의 단점 : 특정 데이터의 저장과 삭제가 느리다. 아예 다 삭제하고 새로 만들어야한다.
//list : 빈번하게 값이 바뀌는 경우
//vector : 값이 변하지 않는 경우

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


	//iList.clear();//전체 삭제
	//iList.remove();//데이터르 기준으로 삭제
	//iList.sort();//오름차순
	//iList.reverse();//순서를 반전
}