/*John Winward
  10/17/2021
  CPSC 250
  Hands-On Exercise 5 */
#include <iostream>

using namespace std;

struct TreeNode
{
	int info;
	TreeNode* left;
	TreeNode* right;
};

void preOrder(TreeNode* r);
void inOrder(TreeNode* r);
void postOrder(TreeNode* r);

int main()
{
	//Initialize root of binary tree
	TreeNode one, two, three, four, five, six,
		seven, eight, nine;
	TreeNode* root = &one;
	one.info = 2;
	one.left = &two;
	one.right = &three;

	//initialize two
	two.info = 7;
	two.left = &four;
	two.right = &five;

	//initialize three
	three.info = 5;
	three.left = NULL;
	three.right = &six;
	
	//initialize four
	four.info = 2;
	four.left = NULL;
	four.right = NULL;

	//initialize five
	five.info = 6;
	five.left = &seven;
	five.right = &eight;

	//initialize six
	six.info = 9;
	six.left = &nine;
	six.right = NULL;

	//initialize seven
	seven.info = 5;
	seven.left = NULL;
	seven.right = NULL;

	//initialize eight
	eight.info = 11;
	eight.left = NULL;
	eight.right = NULL;

	//initialize nine
	nine.info = 4;
	nine.left = NULL;
	nine.right = NULL;

	//Test preOrder
	cout << "Pre-Order Traversal: ";
	preOrder(root);
	cout << endl;

	//Test inOrder
	cout << "In-Order Traversal: ";
	inOrder(root);
	cout << endl;

	//Test postOrder
	cout << "Post-Order Traversal: ";
	postOrder(root);
	cout << endl;

	system("pause");
	return 0;
}

void preOrder(TreeNode* r)
{
	cout << r->info << " ";
	if(r->left != NULL)
		preOrder(r->left);
	if(r->right != NULL)
		preOrder(r->right);
}

void inOrder(TreeNode* r)
{
	if (r->left != NULL)
		inOrder(r->left);
	cout << r->info << " ";
	if (r->right != NULL)
		inOrder(r->right);
}

void postOrder(TreeNode* r)
{
	if (r->left != NULL)
		postOrder(r->left);
	if (r->right != NULL)
		postOrder(r->right);
	cout << r->info << " ";
}