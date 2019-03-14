#include<iostream>
#include"stack.h"

using std::cin;
using std::cout;
using std::endl;

template< template<typename T> class Thing>
class Crab
{
private:
	Thing<int> ti;
	Thing<double> td;
public:
	Crab(){};
	bool push(int a, double b){return ti.push(a) && td.push(b);};
	bool pop(int &a, double &b){return ti.pop(a) && td.pop(b);};
};

int main()
{
	Crab<Stack>cb;
	int ci;
	double cd;
	cout << "Enter (int, double) pairs, such as 3 3.14 (0 0 to end) : \n";
	while(cin >> ci >> cd && ci > 0 && cd > 0 )
	{
		if(!cb.push(ci, cd))
		{
			break;
		}
	}
	while(cb.pop(ci, cd))
	{
		cout << "int double pairs are : " << "( " << ci << " " << cd << " )" << endl; 
	}
	cout << "done . " << endl;
	return 0;
}



