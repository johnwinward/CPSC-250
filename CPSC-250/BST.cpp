/*
	John Winward
	10/25/2021
	CPSC 250
	Hands-On Exercise 6
*/
#include <iostream>

using namespace std;

struct TreeNode
{
	int info;
	TreeNode* left;
	TreeNode* right;
};

void inOrder(TreeNode*);
void insert(TreeNode*&, int);
int countNodes(TreeNode*);
TreeNode* TreeSearch(TreeNode*, int);

int main()
{
	//create Binary Search Tree
	TreeNode* r = NULL;
	insert(r, 10);
	insert(r, 18);
	insert(r, 7);
	insert(r, 2);
	insert(r, 20);
	insert(r, 15);

	inOrder(r);

	system("pause");
	return 0;
}

void inOrder(TreeNode* node)
{
	if (node->left != NULL)
		inOrder(node->left);
	cout << node->info << " ";
	if (node->right != NULL)
		inOrder(node->right);
}

void insert(TreeNode*& node, int num)
{
	TreeNode newNode;
	newNode.left = NULL;
	newNode.right = NULL;
	newNode.info = num;
	while (node != NULL)
		node = node->left;
	node = &newNode;
}

int countNodes(TreeNode* node)
{
	int total = 0;
	if (node->left != NULL)
		total += countNodes(node->left);
	if (node->right != NULL)
		total += countNodes(node->right);
	return total;
}