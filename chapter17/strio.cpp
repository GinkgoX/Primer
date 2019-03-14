#include<iostream>
#include<sstream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	ostringstream outstr;
	string hdisk;
	cout << "What's name of your hard disk ? ";
	getline(cin, hdisk);
	int cap;
	cout << "What's its capacity in GB ? ";
	cin >> cap;
	outstr << "The hard disk " << hdisk << " has a capacity of " << cap << " GB ." << endl;
	string result = outstr.str();
	cout << result;
	istringstream instr(result);
	string words;
	while(instr >> words)
	{
		cout << words << " ";
	}
	cout << endl;
	
	cout << "done . " << endl;
	return 0;
}

