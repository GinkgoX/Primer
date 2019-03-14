/*
#include<iostream>

using namespace std;

int main()
{
	char ch;
	int count = 0;
	cout << "emulate the file system: " << endl;
	//cin.get(ch);
	//while (cin.fail() == false)			//mothod 1 test whether the keyboard input is end with (Ctrl + Z); ie. EOF
	while(cin.get(ch))                      //method 2 to simplify the code, just recall the get() function with once
	{
		cout << ch;
		++count;
		//cin.get(ch);
	}
	cout << count << " characters are recoded ! ";
	return 0;
}
*/








