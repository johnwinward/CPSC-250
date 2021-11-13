/*
	John Winward
	11/13/2021
	CPSC 250
	Hands-On Exercise 8: Balanced Search Trees
*/

#include <iostream>

using namespace std;

struct Node {
	int small;
	int large;
	Node* left;
	Node* middle;
	Node* right;
};

void inOrder(Node* tree);
Node* findItem(Node* tree, int target);

int main() {
	//Create 2-3 tree:
	Node* root;
	Node one, two, three, four, five;
	Node six, seven, eight, nine, ten;
	Node eleven;

	root = &one;

	//Node 1
	one.small = 50;
	one.large = 90;
	one.left = &two;
	one.middle = &three;
	one.right = &four;

	//Node 2
	two.small = 20;
	two.large = NULL;
	two.left = &five;
	two.middle = NULL;
	two.right = &six;

	//Node 3
	three.small = 70;
	three.large = NULL;
	three.left = &seven;
	three.middle = NULL;
	three.right = &eight;

	//Node 4
	four.small = 120;
	four.large = 150;
	four.left = &nine;
	four.middle = &ten;
	four.right = &eleven;

	//Node 5
	five.small = 10;
	five.large = NULL;
	five.left = NULL;
	five.middle = NULL;
	five.right = NULL;

	//Node 6
	six.small = 30;
	six.large = 40;
	six.left = NULL;
	six.middle = NULL;
	six.right = NULL;

	//Node 7
	seven.small = 60;
	seven.large = NULL;
	seven.left = NULL;
	seven.middle = NULL;
	seven.right = NULL;

	//Node 8
	eight.small = 80;
	eight.large = NULL;
	eight.left = NULL;
	eight.middle = NULL;
	eight.right = NULL;

	//Node 9
	nine.small = 100;
	nine.large = 110;
	nine.left = NULL;
	nine.middle = NULL;
	nine.right = NULL;

	//Node 10
	ten.small = 130;
	ten.large = 140;
	ten.left = NULL;
	ten.middle = NULL;
	ten.right = NULL;

	//Node 11
	eleven.small = 160;
	eleven.large = NULL;
	eleven.left = NULL;
	eleven.middle = NULL;
	eleven.right = NULL;

	//Test functions
	cout << "In-order traversal: ";
	inOrder(root);
	cout << "\n\n";

	cout << "Search 50" << endl;
	if (findItem(root, 50))
		cout << "Item found.\n\n";
	else
		cout << "Item not found.\n\n";

	cout << "Search 100" << endl;
	if (findItem(root, 100))
		cout << "Item found.\n\n";
	else
		cout << "Item not found.\n\n";

	cout << "Search 21" << endl;
	if (findItem(root, 21))
		cout << "Item found.\n\n";
	else
		cout << "Item not found.\n\n";

	system("pause");
	return 0;
}

//prints an inorder traversal of the tree
void inOrder(Node* tree) {
	if (tree) {
		if (tree->large) {
			inOrder(tree->left);
			cout << tree->small << " ";
			inOrder(tree->middle);
			cout << tree->large << " ";
			inOrder(tree->right);
		}
		else {
			inOrder(tree->left);
			cout << tree->small << " ";
			inOrder(tree->right);
		}
	}
}

//Return a pointer to the node containing target in the tree
Node* findItem(Node* tree, int target) {
	if (tree) {
		if (tree->right) {
			if (target < tree->small)
				findItem(tree->left, target);
			else if (target > tree->large)
				findItem(tree->right, target);
			else if (target > tree->small && target < tree->large) {
				findItem(tree->middle, target);
			}
			else
				return tree;

		}
		else {
			if (target < tree->small)
				findItem(tree->left, target);
			else if (target > tree->small)
				findItem(tree->right, target);
			else
				return tree;
		}
	}
	else
		return NULL;
}