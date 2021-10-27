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

	//Test
	inOrder(r);
	cout << endl;

	cout << "Count: " << countNodes(r) << endl;

	if (TreeSearch(r, 15))
		cout << "15 is in the BST" << endl;
	else
		cout << "15 is not in the BST" << endl;

	if (TreeSearch(r, 21))
		cout << "21 is in the BST" << endl;
	else
		cout << "21 is not in the BST" << endl;

	system("pause");
	return 0;
}

//Traversal function
void inOrder(TreeNode* node)
{
	if (node->left != NULL)
		inOrder(node->left);
	cout << node->info << " ";
	if (node->right != NULL)
		inOrder(node->right);
}

//insert a node into the BST
void insert(TreeNode*& node, int num)
{
	if (node)
	{
		//When num is less than the node value, recurse with left node
		if (node->info > num)
			insert(node->left, num);
		//Recurse with right node
		else
			insert(node->right, num);
	}
	else //When node is null, create a new node
	{
		node = new TreeNode();
		node->info = num;
	}
}

//Return the # of nodes in the BST
int countNodes(TreeNode* node)
{
	int total = 1; //root of subtree is a node, so count it
	if (node->left != NULL)
		total += countNodes(node->left); //count root of left subtree if it exists
	if (node->right != NULL)
		total += countNodes(node->right); //coutn root of right subtree if it exists
	return total;
}

//Return pointer to node containing num, return null if num is not in BST
TreeNode* TreeSearch(TreeNode* node, int num)
{
	if (node)
	{
		if (node->info == num)
			return node;					//num is equal to node value, return node pointer
		else if (node->info > num)
			TreeSearch(node->left, num);	//num is less than node value, check left node if it exists
		else
			TreeSearch(node->right, num);	//check right node if it exists
	}
	else
		return node;						//return null if node is null (num not found in BST)
}