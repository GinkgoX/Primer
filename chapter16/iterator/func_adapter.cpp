#include<iostream>
#include<vector>
#include<iterator>
#include<functional>
#include<algorithm>

using namespace std;

const int LIM = 5;

void show(double t)
{
	cout.width(6);
	cout << t << " ";
}

int main()
{
	double arr1[LIM] = {1, 2, 3, 4, 5};
	double arr2[LIM] = {5, 4, 3, 2, 1};
	
	vector<double> gr8(arr1, arr1 + LIM);
	vector<double> m8(arr2, arr2 + LIM);
	
	cout.setf(ios_base::fixed);
	cout.precision(1);
	
	cout << "# gr8 #" << endl;
	for_each(gr8.begin(), gr8.end(), show);
	cout << endl;
	
	cout << "# m8 #" << endl;
	for_each(m8.begin(), m8.end(), show);
	cout << endl;
	
	vector<double> sum(LIM);
	transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());
	
	cout << "# sum #" << endl;
	for_each(sum.begin(), sum.end(), show);
	cout << endl;
	
	vector<double> pro(LIM);
	transform(gr8.begin(), gr8.end(), pro.begin(), bind1st(multiplies<double>(), 2.0));
	
	cout << "# product #" << endl;
	for_each(pro.begin(), pro.end(), show);
	cout << endl;
	
	return 0;
}









