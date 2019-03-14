#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string letters;
	cout << "Enter the letter grouping (quit to exit): ";
	while(cin >> letters && letters != "quit")
	{
		cout << "# Permutation of " << letters << " # " <<  endl;
		sort(letters.begin(), letters.end());
		cout << letters << endl;
		while(next_permutation(letters.begin(), letters.end()))
		{
			cout << letters << endl;
		}
		cout << "Enter the next letters(quit to exit) : " ;
	}
	cout << endl;
	return 0;
}

