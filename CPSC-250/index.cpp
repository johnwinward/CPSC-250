/*
	John Winward
	CSPC 250
	jwinward1@live.esu.edu
	11/17/2021
	Programming Assignment 3
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct IndexEntry{
	int acctID;   // (key) Account identifier
	long recNum;  // Record number
};

struct BSTNode {
	IndexEntry data;
	BSTNode* left;
	BSTNode* right;
};

//function declarations
void addNode(IndexEntry, BSTNode*&);
IndexEntry retrieveNode(long, BSTNode*);
void inOrder(BSTNode* node);

int main() {
	//open file
	ifstream accounts;
	accounts.open("accounts.dat");

	//build binary search tree with data from file
	IndexEntry indexEntry;
	BSTNode* r = NULL;

	while (!accounts.eof()) {
		accounts >> indexEntry.acctID;
		accounts >> indexEntry.recNum;
		accounts.ignore(250, '\n');
		addNode(indexEntry, r);
	}

	//prompt user for account retreival
	long idInput;
	cout << "Enter account ID: ";
	cin >> idInput;

	indexEntry = retrieveNode(idInput, r);
	cout << "The matched record number is " << indexEntry.acctID << endl;

	//lookup correct account in records, print
	accounts.clear();
	accounts.seekg(0);

	for (int i = 0; i < indexEntry.acctID; i++)
		accounts.ignore('\n');
	string account;
	getline(accounts, account);
	cout << "Account record from database file:" << endl;
	cout << setw(20) << "Record #" << setw(20) << "Account ID" << setw(20) << "First Name" << setw(20) << "Last Name" <<
		setw(20) << "Balance" << endl;
	cout << account;

	accounts.close();
	system("pause");
	return 0;
}

void addNode(IndexEntry entry, BSTNode*& root) {
	//add new node to BST
	if (root == NULL) {
		root = new BSTNode;
		root->data = entry;
		root->left = NULL;
		root->right = NULL;
	}
	else {
		if (root->data.recNum < entry.recNum)
			addNode(entry, root->right);
		else
			addNode(entry, root->left);
	}
}

IndexEntry retrieveNode(long rNum, BSTNode* root) {
	while (root != NULL){
		if (root->data.recNum < rNum)
			root = root->right;
		else if (root->data.recNum > rNum)
			root = root->left;
		else
			return root->data;
	}
	cout << "Record not found in BST" << endl;
}

void inOrder(BSTNode* node)
{
	if (node->left != NULL)
		inOrder(node->left);
	cout << node->data.recNum << " ";
	if (node->right != NULL)
		inOrder(node->right);
}