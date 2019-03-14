#include<iostream>
using namespace std;

int main(){
	const int Arsize = 20;
	char name[Arsize];
	char dessert[Arsize];
	
	cout << "Enter your name: \n";
	cin.getline(name, Arsize);
	cout << "Enter your favorite dessert: \n";
	cin.getline(dessert, Arsize);
	cout << "Hi " << name << " I have some " << dessert << " for you ! \n";
	return 0;
}


