#include<iostream>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

void show(string name){cout << name <<endl;};

int main()
{
	set<string> Mat;
	set<string> Pat;
	set<string> Party;
	string temp;
	cout << "Enter the name in Mat's name list(quit to exit) " << endl;
	getline(cin, temp);
	while(temp != "quit")
	{
		Mat.insert(temp);
		cout << "Enter the new name(quit to exit) " << endl;
		getline(cin, temp);
	}
	cout << "# Mat info #" << endl;
	for_each(Mat.begin(), Mat.end(), show);
	
	cout << "Enter the name in Pat's name list(quit to exit) " << endl;
	getline(cin, temp);
	while(temp != "quit")
	{
		Pat.insert(temp);
		cout << "Enter the new name(quit to exit) " << endl;
		getline(cin, temp);
	}
	cout << "# Pat info #" << endl;
	for_each(Pat.begin(), Pat.end(), show);
	
	cout << "# Party info #" << endl;
	Party.insert(Mat.begin(), Mat.end());
	Party.insert(Pat.begin(), Pat.end());
	for_each(Party.begin(), Party.end(), show);
	
	cout << "done . " << endl;
	return 0;
}

