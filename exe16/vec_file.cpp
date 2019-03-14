#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iterator>
#include<algorithm>
#include<cstdlib>
#include<cctype>

using namespace std;

char toLower(char ch){return tolower(ch);};
string & ToLower(string &s);
void show(string &s);

int main()
{
	ifstream fin;
	fin.open("readme.txt");
	if(!fin.is_open())
	{
		cout << "Sorry, dose not exist the file ! ";
		exit(EXIT_FAILURE);
	}
	
	vector<string> fv;
	string temp;
	fin >> temp;
	while(fin)
	{
		fv.push_back(temp);
		fin >> temp;
	}
	
	for_each(fv.begin(), fv.end(), show);
	cout << endl;
	
	set<string> fs;
	transform(fv.begin(), fv.end(), insert_iterator<set<string> >(fs, fs.begin()), ToLower);
	set<string>::iterator fi;
	map<string, int> fm;
	for(fi = fs.begin(); fi != fs.end(); ++fi)
	{
		fm[*fi] = count(fv.begin(), fv.end(), *fi);
	}
	
	for(fi = fs.begin(); fi != fs.end(); ++fi)
	{
		cout << *fi << " : " << fm[*fi] << endl; 
	}
	
	fin.close();
	cout << "done . " << endl;
	
	return 0;
}

string & ToLower(string &s)
{
	transform(s.begin(), s.end(), s.begin(), toLower);
	return s;
}

void show(string &s)
{
	cout << s << " ";
}

