#pragma once
#ifndef LIST_H_
#define LIST_H_
#include<string>
using namespace std;

struct Info
{
	string name;
	int id;
};

struct Node
{
	Info val;
	Node *next;
	Node(Info x) :val(x), next(NULL) {}
};

class List
{
private:
	Node * head;
	int length;
public:
	List();
	~List();
	int len();
	int find(const Info val);
	void insert(Info val, int n = 0);
	void remove(Info val);
	void print();
};
#endif

















