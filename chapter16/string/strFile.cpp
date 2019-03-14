
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("tobuy.txt");
	if(fin.is_open() == false)
	{
		cerr << "Can't open the file . Bye \n";
		exit(EXIT_FAILURE);
	}
	
	string item;
	int count = 0;
	getline(fin, item, ':');
	while(fin)
	{
		++count;
		cout << count << " : " << item << endl;
		getline(fin, item, ':');
	}
	
	cout << "done . " << endl;
	fin.close();
	
	return 0;
}

