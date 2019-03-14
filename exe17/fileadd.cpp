#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		cout << "Usage : " << argv[0] << " filename(s)" << endl;
		exit(EXIT_FAILURE);
	} 
	ofstream fout;
	fout.open(argv[1], ios::out | ios::app);
	if(!fout.is_open())
	{
		cout << "Could not open the file . " << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Input the words to add (enter to exit): " << endl;
	string str;
	while(cin.peek() != '\n')
	{
		getline(cin, str);
		cout << str << endl;
		fout << str << endl;
	}
	cout << "done ." << endl;
	fout.close();
	return 0;
}

