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

	system("pause");
	return 0;
}