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
		printf("�Է��Ͻ� %d �� �����մϴ�.\n", num);
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
		printf("%d �� �������� �ʽ��ϴ�.\n", num);

	else
		printf("%d �� �����մϴ�.\n", num);
}

node* FindSmall(node* minNode)
{
	if (minNode->left == NULL) //���� ��庸�� �� �̻� ���� ��尡 ������
		return minNode; //���̻� ���� ��尡 ���� ��带 ����
	minNode = FindSmall(minNode->left);
	return minNode;
}

void FindSmallRight(node* Node, node* minNode) // ����Լ� �����ϴ°� 
{
	if (Node->left == NULL) //minNode���� ���� ��尡 ���ٸ� ����(����)
		return;
	FindSmallRight(Node->left, minNode); // ���ǽĿ� ���� �ʴ´ٸ� minNode�� ���� ���� 
	if (Node->left == minNode) // minNode���� ���� ��尡 ���� ���� ���� ���ٸ� �� �ּ� ���� ������ left�� NULL�̴�. �� right�� ���̵� �ƴϵ� �����ϸ�ȴ�.
		Node->left = minNode->right; // minNode�� ���� ���� ��忡 EndNode���� ū �ڽ� ��带 �޴´�.
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
		else //������ ����� �ڽ� ��尡 �ΰ� ���� ��
		{
			node* replaceNode = NULL; //������带 ��ü�� ���
			replaceNode = root->right; // ������ ����� �ڽ��� ū ��忡�� ���� ���� ��带 ã�� ����
			if (root->right->left != NULL)	//minNode���� ���� ������ ��忡 ������ ��尡 �ִ�
			{
				replaceNode = FindSmall(root->right->left); //���� ���� ��带 ã��
				FindSmallRight(root->right, replaceNode); // rightNode�� minNode�� ����
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
		printf("1.date �߰�\n");
		printf("2.date ����(�̱���)\n");
		printf("3.preorder\n");
		printf("4.inorder\n");
		printf("5.postorder\n");
		printf("6.data �˻�\n");
		printf("7.����\n");
		printf(">>>>>  ");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			printf("data �Է� : ");
			scanf("%d", &num);
			root = Insert(root, num);
			/*system("pause");*/
			break;
		case 2:
			printf("������ data �Է� : ");
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