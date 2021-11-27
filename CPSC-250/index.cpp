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

	//lookup correct account in records, print (if in database)
	if (indexEntry.acctID == -1)
		cout << "Entry not found in database" << endl;
	else {
		accounts.clear();	//reset file read position
		accounts.seekg(0);

		string account;
		for (int i = 0; i < indexEntry.acctID; i++)
			getline(accounts, account);

		cout << "Account record from database file:" << endl;
		cout << left << setw(16) << "Record #" << setw(16) << "Account ID" << setw(16) << "First Name" << setw(16) << "Last Name"
			<< "Balance" << endl;
		for (int i = 0; i < 5; i++) {
			accounts >> account;
			cout << setw(16) << account;
		}
		cout << endl;
	}

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
	if (root != NULL){
		if (root->data.recNum < rNum)
			retrieveNode(rNum, root->right);
		else if (root->data.recNum > rNum)
			retrieveNode(rNum, root->left);
		else
			return root->data;
	}
	else {
		cout << "Record not found in BST" << endl;
		IndexEntry e;
		e.acctID = -1;
		e.recNum = -1;
		return e;
	}
		
}

void inOrder(BSTNode* node)
{
	if (node->left != NULL)
		inOrder(node->left);
	cout << node->data.recNum << " ";
	if (node->right != NULL)
		inOrder(node->right);
}