#include<iostream>
#include<string>

using namespace std;

struct people {char job[20]; char name[20]; int age; double wage;};
people school[2] = {{"Teacher", "XiaoLi", 36, 8700.05},{"Student", "XiaoMing", 21, 1090.45}};
people* office = new people;

int main(){
	
	cout << "people XiaoLi's Occuption is: " << school[0].job << endl;
	cout << "people XiMing's Occuption is:  " << school[1].wage << endl;
	
	cout << "Enter a office job : " ;
	cin.get(office -> job, 20);			//method 1 for member access
	cout << "Enter a office name : ";
	cin >> (*office).name;				//method 2 for member access
	cout << "Enter a office age : ";
	cin >> (*office).age;
	cout << "Enter a office wage : ";
	cin >> office -> wage;
	
	cout << "Office's job is : " << office -> job << endl;			//method 1 for member access
	cout << "Office's name is : " << (*office).name << endl;		//method 2 for member access
	cout << "Office's age is : " << office -> age << endl;
	cout << "Office's wage is : " << office -> wage << endl;
	
	delete office;
	return 0;
}






