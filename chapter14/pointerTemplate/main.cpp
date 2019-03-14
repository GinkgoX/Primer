#include<iostream>
#include<cstdlib>
#include<ctime>
#include"stack.h"

using namespace std;
const int NUM = 10;

int main()
{
	srand(time(0));
	int stacksize;
	cout << "Please enter stack size : ";
	cin >> stacksize;
	Stack<const char *>st(stacksize);
	const char *in[NUM] = {"0 : A", "1 : B", "2 : C", "3 : D", "3 : C", "5 : D", "6 : E", "7 : F", "8 : G", "9 : H"};
	const char *out[NUM];
	int processed = 0;
	int nextin = 0;
	while(processed < NUM)
	{
		if(st.isempty() )
		{
			st.push(in[nextin++]);
		}
		else if(st.isfull() )
		{
			st.pop(out[processed++]);
		}
		else if( (rand() % 2) && (nextin < NUM) )
		{
			st.push(in[nextin++]);
		}
		else
		{
			st.pop(out[processed++]);
		}
	}
	
	for(int i = 0; i < NUM; i++)
	{
		cout << out[i] << endl;
	}
	cout << "done . " << endl;
	return 0; 
}

