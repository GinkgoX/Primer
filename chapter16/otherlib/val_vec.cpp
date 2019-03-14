#include<iostream>
#include<vector>
#include<iterator>
#include<valarray>
#include<algorithm>

using namespace std;

int main()
{
	vector<double> data;
	double temp;
	cout << "Enter number (<= 0 to quit) : " << endl;
	while(cin >> temp && temp > 0)
	{
		data.push_back(temp);
	}
	
	sort(data.begin(), data.end());
	ostream_iterator<double, char> out_iter(cout, " ");
	copy(data.begin(), data.end(), out_iter);
	cout << endl;
	
	int num = data.size();
	
	valarray<double> numbers(num);
	for(int i = 0; i < num; i++)
	{
		numbers[i] = data[i];
	}
	
	valarray<double> sq_rts(num);
	sq_rts = sqrt(numbers);
	valarray<double> results;
	results = numbers + 2.0 * sq_rts;
	cout.setf(ios_base::fixed);
	cout.precision(4);
	for(int i = 0; i < num; i++)
	{
		cout.width(8);
		cout << numbers[i] << " : ";
		cout.width(8);
		cout << results[i] << " " << endl;
	}
	
	cout << "done . " << endl;
	
	return 0;
}









