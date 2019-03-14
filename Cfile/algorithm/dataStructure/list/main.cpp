#include<iostream>
#include"list.h"

using namespace std;

int main()
{
	List list;
	Info items[5] = { { "Alpha", 1 },{ "Beta",2 },{ "Cigma", 3 },{ "Delta", 4 },{ "Epsilon",5 } };

	cout << "insert test: " << endl;
	for (int i = 0; i < 5; i++)
	{
		list.insert(items[i]);
	}
	cout << "The list length is : " << list.len() << endl;
	list.print();
	
	cout << "--------------*---------------" << endl;
	list.insert(items[2]);
	list.insert(items[1], 4);
	list.insert(items[1],1);
	cout << "the list length is : " << list.len() << endl;
	list.print();
	
	cout << "remove test: " << endl;
	list.remove(items[2]);
	cout << "The list length is : " << list.len() << endl;
	cout << "-----------------***------------" << endl;
	list.print();

	list.remove(items[4]);
	cout << "The list length is : " << list.len() << endl;
	list.print();
	cout << "-----------------****------------" << endl;
	return 0;
}

