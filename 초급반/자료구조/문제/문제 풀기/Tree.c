#include<stdio.h>
#include<Windows.h>

#define TRUE 1
#define NULL 0

typedef struct node
{
	int num;
	struct node* left;
	struct node* right;
}node;

node* add_node(int num)
{
	node* tmp;
	tmp = (node*)malloc(sizeof(node));
	tmp->num = num;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

node* Insert(node* root, int num)
{
	if (root == NULL)
		root = add_node(num);
	if (root->num == num)
		printf("입력하신 %d 이 존재합니다.\n", num);
	else if (root->num < num)
		root->right = Insert(root->right, num);
	else if (root->num > num)
		root->left = Insert(root->left, num);
	return root;
}

void PreOrder(node* root)
{
	if (root == NULL)
		return;
	printf("%d  ", root->num);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(node* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	printf("%d  ", root->num);
	InOrder(root->right);
}

void PostOrder(node* root)
{
	if (root == NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d  ", root->num);
}

node* Search(node* root, int searchnum)
{
	if (root == NULL)
		return 0;

	if (root->num == searchnum)
		return root;

	else if (root->num > searchnum)
		return Search(root->left, searchnum);

	else if (root->num < searchnum)
		return Search(root->right, searchnum);
}

node* SearchNum(node* root, int num)
{
	if (Search(root, num) == 0)
		printf("%d 은 존재하지 않습니다.\n", num);

	else
		printf("%d 는 존재합니다.\n", num);
}

node* FindSmall(node* minNode)
{
	if (minNode->left == NULL) //작은 노드보다 더 이상 작은 노드가 없을때
		return minNode; //더이상 작은 노드가 없는 노드를 리턴
	minNode = FindSmall(minNode->left);
	return minNode;
}

void FindSmallRight(node* Node, node* minNode) // 재귀함수 리턴하는것 
{
	if (Node->left == NULL) //minNode보다 작은 노드가 없다면 리턴(종료)
		return;
	FindSmallRight(Node->left, minNode); // 조건식에 맞지 않는다면 minNode에 작은 노드로 
	if (Node->left == minNode) // minNode보다 작은 노드가 가장 작은 노드와 같다면 즉 최소 노드는 무조건 left가 NULL이다. 즉 right가 널이든 아니든 대입하면된다.
		Node->left = minNode->right; // minNode의 가장 작은 노드에 EndNode보다 큰 자식 노드를 받는다.
}

node* Delete(node* root, int delnum)
{
	

	if (root == NULL)
		return NULL;

	if (root->num == delnum)
	{
		if (root->left == NULL && root->right != NULL)
			replaceNode = root->right;
		else if (root->right == NULL && root->left != NULL)
			replaceNode = root->left;
		else if (root->left == NULL && root->right == NULL)
			replaceNode = NULL;
		else //삭제할 노드의 자식 노드가 두개 있을 때
		{
			node* replaceNode = NULL; //삭제노드를 대체할 노드
			replaceNode = root->right; // 삭제할 노드의 자식중 큰 노드에서 가장 작은 노드를 찾기 위함
			if (root->right->left != NULL)	//minNode보다 작은 삭제할 노드에 유사한 노드가 있다
			{
				replaceNode = FindSmall(root->right->left); //가장 작은 노드를 찾음
				FindSmallRight(root->right, replaceNode); // rightNode와 minNode를 연결
				replaceNode->right = root->right;
			}
			replaceNode->left = root->left;

		}
		free(root);
		return replaceNode;
	}
	else if (root->num > delnum)
		root->left = Delete(root->left, delnum);
	else if (root->num < delnum)
		root->right = Delete(root->right, delnum);
	return root;
}

void Relese(node* root)
{
	if (root == NULL)
		return;
	free(root);
	root = NULL;
	Relese(root->left);
	Relese(root->right);
}

void main()
{
	int num;
	node* root = 0;

	while (TRUE)
	{
		system("cls");
		printf("1.date 추가\n");
		printf("2.date 삭제(미구현)\n");
		printf("3.preorder\n");
		printf("4.inorder\n");
		printf("5.postorder\n");
		printf("6.data 검색\n");
		printf("7.종료\n");
		printf(">>>>>  ");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			printf("data 입력 : ");
			scanf("%d", &num);
			root = Insert(root, num);
			/*system("pause");*/
			break;
		case 2:
			printf("삭제할 data 입력 : ");
			scanf("%d", &num);
			root = Delete(root, num);
			//system("pause");
			break;
		case 3:
			PreOrder(root);
			system("pause");
			break;
		case 4:
			InOrder(root);
			system("pause");
			break;
		case 5:
			PostOrder(root);
			system("pause");
			break;
		case 6:
			printf("input data : ");
			scanf("%d", &num);
			SearchNum(root, num);
			system("pause");
			break;
		case 7:
			Relese(root);
			break;
		}
	}
}