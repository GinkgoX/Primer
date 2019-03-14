#include<iostream>
#include<list>
#include<iterator>

using namespace std;

int main()
{
	list<int> one(5 ,2);
	
	int stuff[5] = {1, 2, 8, 4, 6};
	
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);
	int more[6] = {6, 4, 2, 4, 6, 5};
	
	list<int> three(two);
	three.insert(three.end(), more, more + 6);
	
	ostream_iterator<int, char> out_iter(cout, " ");
	
	cout << "# List one #" << endl;
	copy(one.begin(), one.end(), out_iter);
	cout << endl;
	
	cout << "# List two #" << endl;
	copy(two.begin(), two.end(), out_iter);
	cout << endl;
	
	cout << "# List three # " << endl;
	copy(three.begin(), three.end(), out_iter);
	cout << endl;
	
	cout << "# List three remove(2) #" << endl;
	three.remove(2);
	copy(three.begin(), three.end(), out_iter);
	cout << endl;
	
	cout << "# List three splice(three.begin(), one) #" << endl;
	three.splice(three.begin(), one);
	copy(three.begin(), three.end(), out_iter);
	cout << endl;
	
	cout << "# After splice, List one #" << endl;
	copy(one.begin(), one.end(), out_iter);
	cout << endl;
	
	cout << "# List three unique()" << endl;
	three.unique();
	copy(three.begin(), three.end(), out_iter);
	cout << endl;
	
	cout << "# List three sort() & unique() #" << endl;
	three.sort();
	three.unique();
	copy(three.begin(), three.end(), out_iter);
	cout << endl;
	
	cout << "# Sort two merged into three #" << endl;
	two.sort();
	three.merge(two);
	copy(three.begin(), three.end(), out_iter);
	cout << endl;
	
	return 0;
}

