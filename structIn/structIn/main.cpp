#include<iostream>
#include<string>    /*string I/O*/    

using namespace std;

struct Car
{
	string provider;
	int year;
};


int main()
{
	int total_num = 0;
	cout << "How many cars do you wish to catalog ? " ;
	cin >> total_num;
	/*allocate the dynamic struct*/
	Car* car = new Car[total_num];
	
	/*read I/O and save it*/
	for (int i = 0; i < total_num; ++i)
	{
		char ch;
		cout << "Car # "<< i+1 << endl;
		cout << "Please enter the provider : ";
		/*getchar() read Enter to exit, used for clearing the Enter input*/
		getchar();
		getline(cin, car[i].provider);
		cout << "Please enter the made year : " ;
		cin >> car[i].year;
	}
	
	/*traverse the struct*/
	cout << "Here is your collection : " << endl;
	for (int i = 0; i < total_num; ++i)
	{
		cout << car[i].year << " " <<car[i].provider << endl;
	}

	/*release the space*/
	delete[] car;
	return 0;
}

