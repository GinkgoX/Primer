#include<iostream>
#include"list.h"

using namespace std;

List::List()
{
	head = NULL;
	length = 0;
}

List::~List()
{
	Node *temp;
	for (int i = 0; i < length; i++)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

int List::len()
{
	return length;
}

int List::find(const Info val)
{
	Node *temp = head;
	int index = 1;
	while (temp != NULL)
	{
		if (temp->val.name == val.name && temp->val.id == val.id)
		{
			return index;
		}
		temp = temp->next;
		index++;
	}
	return -1;
}

void List::insert(Info val, int n)
{
	if (n < 0)
	{
		cout << "the n must be greater than or equal to zero. " << endl;
		return;
	}
	int index = 1;
	Node *temp = head;
	Node *node = new Node(val);
	if (n == 0)
	{
		node->next = head;
		head = node;
		length++;
		return;
	}
	while (temp != NULL && index < n)
	{
		temp = temp->next;
		index++;
	}
	if (temp == NULL)
	{
		cout << "insert fail !" << endl;
		return;
	}
	node->next = temp->next;
	temp->next = node;
	length++;
}

void List::remove(Info val)
{
	int n = find(val);
	if (n == -1)
	{
		cout << "remove fail ! " << endl;
		return;
	}
	if (n == 1)
	{
		head = head->next;
		length--;
		return;
	}
	int index = 2;
	Node *temp = head;
	while (index < n)
	{
		temp = temp->next;
	}
	temp->next = temp->next->next;
	length--;
}

void List::print()
{
	if (head == NULL)
	{
		cout << "list is already empty ! " << endl;
		return;
	}
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->val.name << " , " << temp->val.id << endl;
		temp = temp->next;
	}
	cout << endl;
}
