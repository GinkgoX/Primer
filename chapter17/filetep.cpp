#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	cout << "This system can generate up to " << TMP_MAX << " temporary names of up to " << L_tmpnam << "characters ." << endl;
	char pszName[L_tmpnam] = " ";
	cout << "Here are ten names : " << endl;
	for(int i = 0; i < 10; i++)
	{
		tmpnam(pszName);
		cout << pszName << endl;
	}
	cout << "done . " << endl;
	return 0;
}

