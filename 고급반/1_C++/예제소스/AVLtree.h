#pragma once
#include "Node.h"

class AVLTree
{
private:
	TreeNode* root;
	int count;

	const int get_height(TreeNode*);
	TreeNode* new_node(int);
	TreeNode* rotate_LL(TreeNode*);
	TreeNode* rotate_RR(TreeNode*);
	TreeNode* rotate_LR(TreeNode*);
	TreeNode* rotate_RL(TreeNode*);
	TreeNode* balance_tree(TreeNode*);
	TreeNode* search_count(TreeNode*, const int&);
	TreeNode* insert(TreeNode*, int);
	TreeNode* min_key_node(TreeNode*);
	TreeNode* remove(TreeNode*, const int&);
	void inoder_print(TreeNode*);
public:
	AVLTree() : count(0) { this->root = NULL; }
	~AVLTree();

	const int get_balance_factor(TreeNode*);
	void search_count(const int&);
	void insert(int);
	void remove(const int&);

	void inoder_print();
};

AVLTree::~AVLTree()
{
	while (NULL != this->root)
	{
		this->root = remove(this->root, this->root->get_key());
	}
}

const int AVLTree::get_height(TreeNode* node)
{
	if (NULL == this->root || NULL == node) return NULL;

	// NULL�� �ƴ϶�� ��Ʈ 1���� ������ �ִ�. ���̴� �ּ� 1.
	return 1 + std::max(get_height(node->left), get_height(node->right));
}

TreeNode* AVLTree::new_node(int key)
{
	return new TreeNode(key);
}

// �θ��� ���ʿ� �ڽ��� �ְ� �� �ڽ��� ���ʿ� �ڽ��� ���� ���.
// ���������� ȸ���Ѵ�.
TreeNode* AVLTree::rotate_LL(TreeNode* node)
{
	if (NULL == this->root || NULL == node) return NULL;

	TreeNode* child = node->left;	// ���ʿ� �ִ� �ڽ��� ã�´�.
	node->left = child->right;	// ���ʿ��� �ڽ��� ������(NULL) �ڽ��� ���´�.
	child->right = node;			// �θ� �ڽ��� ������ ����(�θ�� �ڽ��� �ٲ��).

	return child;
}

// �θ��� �����ʿ� �ڽ��� �ְ� �� �ڽ��� �����ʿ� �ڽ��� ���� ���.
// �������� ȸ���Ѵ�.
TreeNode* AVLTree::rotate_RR(TreeNode* node)
{
	if (NULL == this->root || NULL == node) return NULL;

	TreeNode* child = node->right;// �����ʿ� �ִ� �ڽ��� ã�´�.
	node->right = child->left;	// �����ʿ��� �ڽ��� ����(NULL) �ڽ��� ���´�.
	child->left = node;			// �θ� �ڽ��� ���� ����(�θ�� �ڽ��� �ٲ��).

	return child;
}

// �θ��� ���ʿ� �ڽ��� �ְ� �� �ڽ��� �����ʿ� �ڽ��� ���� ���.
// ������ �������� ȸ���Ѵ�.
TreeNode* AVLTree::rotate_LR(TreeNode* node)
{
	if (NULL == this->root || NULL == node) return NULL;

	TreeNode* child = node->left;
	node->left = rotate_RR(child);//�ڽ��� �����ʿ� �ڽ��� �ֱ⶧����RRȸ���� �Ѵ�.

	return rotate_LL(node);		//���� �ڽ��� ���ʿ� �����Ƿ� LLȸ���� �ٽ����ش�.
}

// �θ��� �����ʿ� �ڽ��� �ְ� �� �ڽ��� ���ʿ� �ڽ��� ���� ���.
// ���� ���������� ȸ���Ѵ�.
TreeNode* AVLTree::rotate_RL(TreeNode* node)
{
	if (NULL == this->root || NULL == node) return NULL;

	TreeNode* child = node->right;
	node->right = rotate_LL(child);

	return rotate_RR(node);
}

const int AVLTree::get_balance_factor(TreeNode* node)
{
	if (NULL == node) return 0;

	// ���� �μ�(balance factor) = ���� ���� - ������ ����.
	// �������� ������ ������ ��� ���������� ������ ������ ����.
	return get_height(node->left) - get_height(node->right);
}

TreeNode* AVLTree::balance_tree(TreeNode* node)
{
	const int& bf = get_balance_factor(node);
	if (1 < bf)			// balance factor�� 1���� ũ�� �������� ġ���� �ִ�.
	{
		if (0 < get_balance_factor(node->left))
		{
			return rotate_LL(node);
		}
		else
		{
			return rotate_LR(node);
		}
	}
	else if(-1 > bf)	// balance factor�� -1���� ������ ���������� ġ���� �ִ�.
	{
		if (0 > get_balance_factor(node->right))
		{
			return rotate_RR(node);
		}
		else
		{
			return rotate_RL(node);
		}
	}

	return node;
}

TreeNode* AVLTree::search_count(TreeNode* node, const int& key)
{
	if (NULL == node) return NULL;

	this->count++;

	if (key == node->get_key()) return node;
	else if (key > node->get_key()) return search_count(node->right, key);	// Ű ���� ���� Ű ������ ũ�� ������,
	else return search_count(node->left, key);								// ������ ������ ã�´�.
}

void AVLTree::search_count(const int& key)
{
	search_count(this->root, key);

	std::cout << this->count << "�� �˻�" << std::endl;
	this->count = 0;
}

TreeNode* AVLTree::insert(TreeNode* node, int key)
{
	try
	{
		if (NULL == node) return new_node(key);

		if (node->get_key() > key)		// Ű ���� ���� ����� Ű ������ ������ ���ʿ� ����.
		{
			node->left = insert(node->left, key);
		}
		else if (node->get_key() < key)	// Ű ���� ���� ����� Ű ������ ũ�� �����ʿ� ����.
		{
			node->right = insert(node->right, key);
		}
		else
		{
			std::cerr << "�ߺ� ������ ����!!" << std::endl;
			return node;
		}

		return balance_tree(node);
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	return node;
}

void AVLTree::insert(int key)
{
	this->root = insert(this->root, key);
}

TreeNode* AVLTree::min_key_node(TreeNode* node)
{
	if (NULL == node) return NULL;
	if (NULL == node->left) return node;
	return min_key_node(node->left);
}

TreeNode* AVLTree::remove(TreeNode* node, const int& key)
{
	if (NULL == node) return NULL;

	if (node->get_key() > key) node->left = remove(node->left, key);		// Ű ���� ������ ���� �ڽĿ��� ã�� ����.
	else if (node->get_key() < key) node->right = remove(node->right, key);	// Ű ���� ũ�� ������ �ڽĿ��� ã�� ����.
	else
	{
		TreeNode* child = NULL;
		// ������ �����͸� ã�Ұ�,
		if (NULL == node->left || NULL == node->right)
		{
			// �� �ʿ� �ڽ��� �ְų� �� �ʴ� ���� ���.
			// ���� �������� Ȯ���Ͽ� �ڽ� ��带 ����� �д�.
			if (NULL == node->left) child = node->right;
			else child = node->left;

			// �ڽ��� ����.
			delete node;

			node = child;
		}
		else
		{
			// �� �ʿ� �ڽ��� ���� ���.
			child = min_key_node(node->right);					// ������ �ڽ� �߿��� ���� ���� Ű ���� ���� �ڽ��� ã�ƿ´�.
			node->set_key(child->get_key());					// �����͸� ����. ���⼭�� Ű ������ �����Ѵ�.
			node->right = remove(node->right, child->get_key());// ���� Ű ���� ������ �����͸� ���� �� ���� ������ �ش� ���� ���� �ڽ��� �����Ѵ�.
		}
	}

	if (NULL == node) return NULL;

	return balance_tree(node);
}

void AVLTree::remove(const int& key)
{
	this->root = remove(this->root, key);
}

void AVLTree::inoder_print(TreeNode* node)	// Ű ���� ���� �������� ������ ������ ����Ѵ�.
{
	if (NULL != node)
	{
		inoder_print(node->left);

		std::cout << "key:" << node->get_key() << std::endl;

		inoder_print(node->right);
	}
}

void AVLTree::inoder_print()
{
	inoder_print(this->root);
}