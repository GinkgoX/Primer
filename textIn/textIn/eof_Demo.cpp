#include<iostream>

using namespace std;

int main()
{
	int ch;
	int count = 0;
	cout << "Emulate the file system :" << endl;
	while ((ch = cin.get()) != EOF)					//ch = cin.get() return a int ASCII code; cin.get() return a cin object
	{
		cout.put(ch);                               //cout.put(ch) force the int type to return a char type
		++count;
	}
	cout << endl << count << " characters are recored !";
	return 0;
}
















