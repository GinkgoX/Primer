#include<iostream>

using namespace std;

int main()
{
	char ch;
	int n = 0;
	cout << "Enter the characters ('$' to exit) : ";
	while(cin.peek() != '$')
	{
		cin.get(ch);
		if(ch != '$')
		{
			n++;
			cout << ch;
		}
	}
	cin >> ch;
	cout << endl;
	cout << "Total " << n << " characters ."<< endl;
	cout << "Next character is " << ch << endl;
	cout << "done . " << endl;
	return 0;
}

