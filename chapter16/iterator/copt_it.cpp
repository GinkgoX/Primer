#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

int main()
{
	int casts[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int>dice(10);
	copy(casts, casts + 10, dice.begin());
	cout << "Let the dice be cast ! " << endl;
	ostream_iterator<int, char> out_iter(cout, " ");
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	
	cout << "Implicit use of reverse iterator . " << endl;
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;
	
	cout << "Explicit use of reverse iterator . " << endl;
	vector<int>::reverse_iterator ri;
	for(ri = dice.rbegin(); ri != dice.rend(); ++ri)
	{
		cout << *ri << " ";
	}
	cout << endl;
	
	return 0;
}

