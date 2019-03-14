#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool revs(string &s);

int main()
{
	string temp;
	cout << "Enter a scentence or words (quit to exit) : ";
	getline(cin, temp);
	while(temp != "quit")
	{
		if(revs(temp))
		{
			cout << "Yes, it's palindrome . " << endl;
		}
		else
		{
			cout << "No, it's not a palindrome . " << endl;
		}
		cout << "Enter the new scentence or words (quit to exit) : ";
		getline(cin, temp);
	}
	cout << "done . " << endl;
	return 0;
}

bool revs(string &s)
{
	string temp = s;
	reverse(temp.begin(), temp.end());
	return (temp == s);
}

