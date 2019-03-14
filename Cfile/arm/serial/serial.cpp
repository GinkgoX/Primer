#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	for(int i = 0; i < 2; i++)
	{
		cout << "Please enter any : ";
		getline(cin, s);
		cout << s << endl;
		int n = s.length();
		cout << "Len " << n << endl;
	}
	return 0;
}
