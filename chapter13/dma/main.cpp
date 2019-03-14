#include<iostream>
#include"dma.h"

using namespace std;

int main()
{
	baseDMA *p_b[5];
	
	for(int i = 0; i < 5; i++)
	{
		char lb[40];
		int r;
		char c;
		cout << "Enter the label : " ;
		cin>>lb;
		cout << "Enter the rate : ";
		cin >> r;
		cout << "Enter 1(bassDMA) , 2(lacksDMA), 3(hasDMA) to save your date :";
		cin >> c;
		
		switch(c)
		{
			case '1':
				p_b[i] = new baseDMA(lb, r);
				break;
			case '2':
				char co[40];
				cout << "Enter the color :";
				cin>>co;
				cin.get();
				p_b[i] = new lacksDMA(co, lb, r);
				break;
			case '3':
				char st[40];
				cout << "Enter the style : ";
				cin>>st;
				cin.get();
				p_b[i] = new hasDMA(st, lb, r);
				break;
			default:
				cout << "Only 1 , 2, 3 is allowed to enter !" << endl;
		}
	}
	cout << "Tthe date you enter are following : " << endl;
	for(int i = 0; i < 5; i++)
	{
		cout << "# " << i + 1 << " : " << endl ;
		p_b[i]->show();
		cout << endl;
	}
	
	for(int i = 0; i < 5; i++)
	{
		delete p_b[i];
	}
	cout << "done . " << endl;
	return 0;
}

