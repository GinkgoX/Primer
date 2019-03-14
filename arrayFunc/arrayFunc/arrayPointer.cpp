/*
#include<iostream>

using namespace std;

const int Arsize = 8;

int sum_range(const int* begin, const int* end);		//the begin/end pointer of an array;

int main()
{
	int cookie[Arsize] = {1, 2, 4, 8, 16, 32, 64, 128};
	int sum = sum_range(cookie, cookie + Arsize);
	cout << "Total sum of cookies : " << sum << endl;
	 sum = sum_range(cookie, cookie + 3);
	cout << "The first 3 sum of cookies : " << sum << endl;
	sum = sum_range(cookie + 4, cookie + 8);
	cout << "The last 4 sum of cookies : " << sum << endl;
	return 0;
}

int sum_range(const int* begin, const int* end)
{
	int total = 0;
	const int* pt;										//pointer type should be the same;
	for (pt = begin; pt != end; pt++)
	{
		total = total + *pt;
	}
	return total;
}
*/

