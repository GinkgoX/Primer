#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

void show(int v);

int main()
{
	int arr[10] = {4,5 ,4, 2, 2, 3, 4, 8, 1, 4};
	list<int> la(arr, arr + 10);
	list<int> lb(la);
	
	cout << "# original list info # " << endl;
	for_each(la.begin(), la.end(), show);
	cout << endl;
	
	cout << "# after using remove() method #" << endl;
	la.remove(4);
	for_each(la.begin(), la.end(), show);
	cout << endl;
	
	cout << "# after using remove() function #" << endl;
	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4);
	for_each(lb.begin(), lb.end(), show);
	cout << endl;
	
	cout << "# after using the erase() method #" << endl;
	lb.erase(last, lb.end());
	for_each(lb.begin(), lb.end(), show);
	cout << endl;
	
	return 0;
}


void show(int v)
{
	cout.width(4);
	cout << v << " ";
}











