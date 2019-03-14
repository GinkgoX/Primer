/*
#include<iostream>
#include<climits>	//contains INT_MAX, INT_MIN

using namespace std;

bool is_int(double x);

int main()
{
	double x;
	cout << "Enter an integer: ";
	cin >> x;
	while (!is_int(x))
	{
		cout << "out of range, please enter again ! ";
		cin >> x;
	}
	cout << "The integer you enter is " << int(x) << endl;
	return 0;
}

bool is_int(double x)
{
	if (x < INT_MAX && x > INT_MIN)
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/