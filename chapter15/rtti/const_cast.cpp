#include<iostream>

using namespace std;

void change(const int *p, int n);

int main()
{
	//const_cast demo
	int test1 = 10010;
	const int test2 = 10086;
	cout << "( test1, test2 ) = " << "( " << test1 << " , " << test2 << " )" << endl;
	change(&test1, -1);
	change(&test2, -1);
	cout << "( test1, test2 ) = " << "( " << test1 << " , " << test2 << " )" << endl;
	return 0;
}


void change(const int *p, int n)
{
	int *pc;
	if(n < 0)
	{
		pc = const_cast<int *>(p);
		*pc = 100;
	}
}

