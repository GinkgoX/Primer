#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	string filein;
	cout << "Enter the filename you want to write : ";
	cin >> filein;
	ofstream fout(filein.c_str());
	string content;
	cout << "Enter the content you want to save (save to end):" << endl;
	cin >> content;
	char ch;
	while(content != "save")
	{
		fout << content << " ";
		cin >> content;
		ch = cin.get();
		if(ch == '\n')
		{
			fout << endl;
		}
	}
	cout << "Save the file successfully !" << endl;
	cout << "Enter your secret number : " ;
	float secret;
	cin >> secret;
	fout << "your secret number is " << secret << endl;
	fout.close();
	
	cout << "Enter the filename you want to open : ";
	string fileout;
	cin >> fileout;
	if(filein == fileout)
	{
		ifstream fin(fileout.c_str());
		cout << "Enter the file secret number : ";
		float passnum;
		cin >> passnum;
		if(passnum == secret)
		{
			char ch;
			while(fin.get(ch))
			{
				cout << ch;
			}
			cout << "done . " << endl;
		}
		else
		{
			cout << "wrong secret number !" << endl;
		}
	}
	else
	{
		cout << "There does not exit the file you enter." << endl;
	}
	
	return 0;
}

