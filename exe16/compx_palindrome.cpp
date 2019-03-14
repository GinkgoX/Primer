#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>

using namespace std;

bool revs(string &s);

int main()
{
	string temp;
	cout << "Enter a scentence or words(quit to exit) : ";
	getline(cin, temp);
	while(temp != "quit")
	{
		if(revs(temp))
		{
			cout << "Yes, it's a palindrome ." << endl;
		}
		else
		{
			cout << "No, it's not a palindrome ." << endl;
		}
		cout << "Enter new scentence or words(quit to exit) : ";
		getline(cin, temp);
	}
	return 0;
}

bool revs(string &s)
{
	string temp;
	int num = s.size();
	for(int i = 0; i < num; i++)
	{
		if(isalpha(s[i]))
		{
			temp += tolower(s[i]);
		}
	}
	string temp1 = temp;
	reverse(temp1.begin(), temp1.end());
	return (temp1 == temp);
}

