#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		cout << "Usage " << argv[0] << "filename(destination) filename(source)" << endl;
		exit(EXIT_FAILURE);
	}
	ofstream fout;
	fout.open(argv[1], ios::out | ios::app);
	if(!fout.is_open())
	{
		cout << "Could not open the " << argv[1] << endl;
		exit(EXIT_FAILURE);
	}
	
	ifstream fin;
	fin.open(argv[2]);
	if(!fin.is_open())
	{
		cout << "Could not open the " << argv[2] << endl;
		exit(EXIT_FAILURE);
	}
	
	char ch;
	while(fin.get(ch))
	{
		fout << ch;
	}
	fin.close();
	fout.close();
	cout << "done . " << endl;
	return 0;
}

