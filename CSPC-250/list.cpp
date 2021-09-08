#include <iostream>

using namespace std;

struct ListNode
{
	int value;
	ListNode* next;
};

void printNode(ListNode*);
int lengthList(ListNode*);

int main()
{
	ListNode a, b, c;

	a.value = 3;
	b.value = 8;
	c.value = 10;

	a.next = &b;
	b.next = &c;
	c.next = NULL;

	//test print function
	printNode(&a);

	//test length function
	cout << "The length of the list is " << lengthList(&a) << endl;

	system("pause");
	return 0;
}

void printNode(ListNode* start)
{
	cout << "List: ";
	while (start)
	{
		cout << start->value << " ";
		start = start->next;
	}
	cout << endl;
}

int lengthList(ListNode* start)
{
	int length = 0;
	while (start)
	{
		length++;
		start = start->next;
	}
	return length;
}