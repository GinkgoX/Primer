#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<algorithm>
#include<iterator>

using namespace std;

int main()
{
	ifstream fin;
	string fname;
	set<string> party;
	cout << "Enter the Mat friends name : ";
	getline(cin, fname);
	fin.open(fname.c_str());
	if(!fin.is_open())
	{
		cout << "Could not open the " << fname << endl;
		exit(EXIT_FAILURE); 
	}
	string temp;
	while(!fin.eof())
	{
		getline(fin, temp);
		cout << temp << endl;
		party.insert(temp);
	}
	fin.close();
	
	cout << "Enter the Pet friends name : ";
	getline(cin, fname);
	fin.open(fname.c_str());
	if(!fin.is_open())
	{
		cout << "Could not open the " << fname << endl;
		exit(EXIT_FAILURE); 
	}
	while(!fin.eof())
	{
		getline(fin, temp);
		cout << temp << endl;
		party.insert(temp);
	}
	fin.close();
	
	cout << "Enter the Party friends name : ";
	ofstream fout;
	getline(cin, fname);
	fout.open(fname.c_str());
	if(!fout.is_open())
	{
		cout << "Could not open the " << fname << endl;
		exit(EXIT_FAILURE); 
	}

	ostream_iterator<string, char> outer(cout, " ");
	copy(party.begin(), party.end(), outer);
	
	
	ostream_iterator<string, char> fouter(fout, " ");
	copy(party.begin(), party.end(), fouter);
	fout.close();
	
	cout << "done . " << endl;
	
	return 0;
}
