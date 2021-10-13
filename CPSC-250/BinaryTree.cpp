/*John Winward
  10/13/2021
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
	three.right = &six;
	
	//initialize four
	four.info = 2;

	//initialize five
	five.info = 6;
	five.left = &seven;
	five.right = &eight;

	//initialize six
	six.info = 9;
	six.left = &nine;

	//initialize seven
	seven.info = 5;

	//initialize eight
	eight.info = 11;

	//initialize nine
	nine.info = 4;

	system("pause");
	return 0;
}