#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iterator>
#include<cctype>

using namespace std;

char toLower(char ch){return tolower(ch);};
void show(const string &s){cout << s << " ";};
string ToLower(string &s);

int main()
{
	vector<string> words;
	string input;
	cout << "Enter the words (quit to exit): " << endl;
	while(cin >> input && input != "quit")
	{
		words.push_back(input);
	}
	
	cout << "# the words you enter as follows #" << endl;
	for_each(words.begin(), words.end(), show);
	cout << endl;
	
	cout << "# Alphabetic list of words #" << endl;
	set<string> wordset;
	transform(words.begin(), words.end(), insert_iterator<set<string> >(wordset, wordset.begin()), ToLower);
	for_each(wordset.begin(), wordset.end(), show);
	cout << endl;
	
	cout << "# word frequency #" << endl;
	map<string, int> wordmap;
	set<string>::iterator si;
	for(si = wordset.begin(); si != wordset.end(); ++si)
	{
		wordmap[*si] = count(words.begin(), words.end(), *si);
	}
	for(si = wordset.begin(); si != wordset.end(); ++si)
	{
		cout << *si << " :  " << wordmap[*si] << endl;
	}
	
	cout << "done . " << endl;
	
	return 0;
}


string ToLower(string &s)
{
	transform(s.begin(), s.end(), s.begin(), toLower);
	return s;
}








