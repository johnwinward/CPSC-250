/*
	John Winward
	12/1/21
	CPSC 250
	Hands-On Exercise 9
*/
#include <iostream>

using namespace std;

const int  CAPACITY = 10;

void initTable(int data[]);
void printTable(int data[]);
int hash_function(int key);
void hashInsert(int data[], int key);
bool key_occurs(int data[], int search_key);

int main() {

	//initialize hash table
	int hashTable[CAPACITY];
	initTable(hashTable);

	//insert some values
	cout << "Inserting 10, 22, 11, 31, 24, 88, 38, and 21" << endl;

	hashInsert(hashTable, 10);
	hashInsert(hashTable, 22);
	hashInsert(hashTable, 11);
	hashInsert(hashTable, 31);
	hashInsert(hashTable, 24);
	hashInsert(hashTable, 88);
	hashInsert(hashTable, 38);
	hashInsert(hashTable, 21);

	printTable(hashTable);

	cout << endl;

	//search for some values (11 first)
	if (key_occurs(hashTable, 11))
		cout << "11 is found." << endl;
	else
		cout << "11 is not found." << endl;

	//31
	if (key_occurs(hashTable, 31))
		cout << "31 is found." << endl;
	else
		cout << "31 is not found." << endl;

	//23
	if (key_occurs(hashTable, 23))
		cout << "23 is found." << endl;
	else
		cout << "23 is not found." << endl;

	system("pause");
	return 0;
}

//Initializes hash table (open spaces are stored as -1)
void initTable(int data[]) {
	for (int i = 0; i < CAPACITY; i++)
		data[i] = -1;
}

//Prints table
void printTable(int data[]) {
	cout << "Table: ";
	for (int i = 0; i < CAPACITY; i++)
		cout << data[i] << " ";
	cout << endl;
}

//Returns hash table index
int hash_function(int key) {
	return key % CAPACITY;
}

//Inserts key to hash table using quadratic probing
void hashInsert(int data[], int key) {
	int pos = hash_function(key);
	int q = 1;
	while (data[pos] != -1) {
		pos = (hash_function(key) + q * q) % CAPACITY;
		q++;
		if (q > CAPACITY)
			break;
	}
	data[pos] = key;
}

//Returns true if the key is in the hash table
bool key_occurs(int data[], int search_key) {
	int pos = hash_function(search_key);
	int q = 1;
	while (data[pos] != search_key && data[pos] != -1) {
		pos = (hash_function(search_key) + q * q) % CAPACITY;
		q++;
	}
	if (data[pos] == search_key)
		return true;
	else
		return false;
}