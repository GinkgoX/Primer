#include<iostream>
#include<cctype>
#include<string>
#include"stack.h"

using namespace std;

int main()
{
	Stack<string> st;
	char ch;
	string po;
	cout << "Please enter A : add a purchase order, P : process a goods, Q : quit . " << endl;
	while((cin >> ch) && (toupper(ch) != 'Q'))
	{
		while(cin.get() != '\n')
		{
			continue;
		}
		if(!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch(ch)
		{
			case 'A':
			case 'a':
						cout << "Enter a goods number to add : ";
						cin >> po;
						if(st.isfull() ) 
						{
							cout << "stack is already full ! " << endl;
						}
						else
						{
							st.push(po);
						}
						break;
			case 'P':
			case 'p':
						if(st.isempty() )
						{
							cout << "stack is already empty ! " << endl;
						}
						else
						{
							st.pop(po);
							cout << "PO # " << po << " poped \n";
						}
						break;
		}
		cout << "Please enter A : add a purchase order, P : process a goods, Q : quit . " << endl;
	}
	cout << "done . " << endl;
	return 0;
}







