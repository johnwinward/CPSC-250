#include <iostream>

using namespace std;

void Insert(int data[], int item, int& length);
bool isEmpty(int[], int size);
bool isPresent(int data[], int item, int length);
void Delete(int data[], int item, int& length);
void printList(int data[], int length);

int const SIZE = 32;

int main()
{
	//initialize array
	int data[SIZE];
	int length = 0;

	//insert 5, 10, 15, and 20
	Insert(data, 5, length);
	Insert(data, 10, length);
	Insert(data, 15, length);
	Insert(data, 20, length);

	//print results
	printList(data, length);

	//find if 10 is in the list
	cout << "Is 10 in the list?" << endl;
	if (isPresent(data, 10, length))
		cout << "The number is in the list." << endl;
	else
		cout << "The number is not in the list" << endl;

	//check value that isn't in the list
	cout << "Is 12 in the list?" << endl;
	if (isPresent(data, 12, length))
		cout << "The number is in the list." << endl;
	else
		cout << "The number is not in the list" << endl;

	//delete 10
	cout << "Deleting 10..." << endl;
	Delete(data, 10, length);

	//reprint list
	printList(data, length);

	//remove other data
	cout << "Deleting other values..." << endl;
	Delete(data, 5, length);
	Delete(data, 15, length);
	Delete(data, 20, length);

	//check if list is empty
	if (isEmpty(data, length))
		cout << "The list is empty." << endl;
	else
		cout << "The list is not empty >:(" << endl;

	system("pause");
	return 0;
}

void Insert(int data[], int item, int& length)
{
	data[length] = item; //insert item
	length++; //length of list is increased
	cout << item << " was added to the list." << endl;
}

bool isEmpty(int data[], int size)
{
	if (size == 0)
		return true;
	else
		return false;
}

bool isPresent(int data[], int item, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == item)
			return true;
	}

	return false;
}

void Delete(int data[], int item, int& length)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == item)
		{
			for (int j = i; j < length - 1; j++)
			{
				data[j] = data[j + 1];
			}
			break;
		}

	}
	length--;
}

void printList(int data[], int length)
{
	cout << "List: ";
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
}