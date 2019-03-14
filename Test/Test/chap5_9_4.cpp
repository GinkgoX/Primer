#include<iostream>

using namespace std;

int main()
{
	const int Month = 12;
	const char* Year[Month] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	int books[Month];
	cout << "Enter the whole year's sell scales: ";
	for(int i = 0; i < Month;++i)
	{
		cout << "Enter the whole year's sell scales: ";
		cin >> books[i];
		cout << Year[i] << " sells " << books[i] << " books" << endl;
	}
	return 0;
}













