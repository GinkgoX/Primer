#include<iostream>
#include"sales.h"

using namespace std;

int main()
{
	double s1[12] = {1978, 1989, 1996, 1967, 1994, 1993, 1986, 1999, 1978, 1984, 1983, 1992};
	double s2[12] = {12, 13, 14, 11, 14, 16, 14, 18, 13, 12, 16, 17};
	
	Sales sa1(2001, s1, 12);
	LabelSales sa2(2004, s2, 12, "BlogStar");
	
	cout << "First try block : \n";
	try
	{
		int i; 
		cout << "Year : " << sa1.year_val() << endl;
		for(i = 0; i < 12; i++)
		{
			cout << sa1[i] << " ";
			if(i % 6 == 5)
			{
				cout << endl;
			}
		}
		cout << "Year : " << sa2.year_val() << endl;
		cout << "Label : " << sa2.label_val() << endl;
		for(i = 0; i < 12; i++)
		{
			cout << sa2[i] << " ";
			if(i % 6 == 5)
			{
				cout << endl;
			}
		}
 		cout << "End of first block :\n";
	}
	
	catch(LabelSales::nbad_index &bad)
	{
		cout << bad.what();
		cout << "Company : " << bad.lbl_val() << endl;
		cout << "Bad index : " << bad.bi_val() << endl;
	}
	
	catch(Sales::bad_index &bad)
	{
		cout << bad.what();
		cout << "Bad index : " << bad.bi_val() << endl;
	}
	
	cout << "Next try block : \n";
	try
	{
		sa2[2] = 22.0;
		sa2[20] = 32;
		cout << "End of second block : \n";
	}
	catch(LabelSales::nbad_index &bad)
	{
		cout << bad.what();
		cout << "Company : " << bad.lbl_val() << endl;
		cout << "Bad index : " << bad.bi_val() << endl;
	}
	catch(Sales::bad_index &bad)
	{
		cout << bad.what();
		cout << "Bad index : " << bad.bi_val() << endl;
	}
	
	cout << "done . " << endl;
	return 0;
}

