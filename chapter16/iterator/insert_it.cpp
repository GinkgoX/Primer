#include<iostream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

int main()
{
	string s1[4] = {"fine", "final", "feast", "favorate"};
	string s2[2] = {"busy", "bats"};
	string s3[2] = {"singer", "signal"};
	
	vector<string>words(4);
	copy(s1, s1 + 4, words.begin());
	
	ostream_iterator<string, char> out_iter(cout, " ");
	copy(words.begin(), words.end(), out_iter);
	cout << endl;
	
	copy(s2, s2 + 2, back_insert_iterator<vector<string> >(words));
	copy(words.begin(), words.end(), out_iter);
	cout << endl;
	
	copy(s3, s3 + 2, insert_iterator<vector<string> >(words, words.begin()));
	copy(words.begin(), words.end(), out_iter);
	cout << endl;
	
	return 0;
}

