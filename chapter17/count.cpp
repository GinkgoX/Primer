#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		cout << "Usage : " << argv[0] << " filename(s) \n";
		exit(EXIT_FAILURE); 
	}
	ifstream fin;
	long count;
	long total = 0;
	char ch;
	for(int i = 1; i < argc; i++)
	{
		fin.open(argv[i]);
		if(!fin.is_open())
		{
			cerr << "Could not open " << argv[i] << endl;
			fin.clear();
			continue;
		}
		count = 0;
		while(fin.get(ch))
		{
			if(ch == '\n')
			{
				count++;
			}
		}
		cout << count << " 	lines in " << argv[i] << endl;
		total += count;
		fin.clear();
		fin.close();
	}
	cout << total << "	lines in all \n" ;
	cout << "done . " << endl;
	return 0;
}

