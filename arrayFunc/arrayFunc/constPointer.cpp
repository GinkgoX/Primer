#include<iostream>

using namespace std;

int mian()
{
	// case 1:
	int age = 20;
	const int* pt = &age;		//const pointer points to a variable;
	age = 18;					//changing variable result the change for age;  
	cout << "age is : " << age << "and *pt is :" << *pt << endl;  //*pt = 18;
	
	//case 2:
	const float g_earth = 9.80;
	const float* p_g = &g_earth;

	//case 3:(not vaild)
	//const float g_moon = 1.63;
	//float* p_m = &g_moon;

	//more complex
	int id = 20;			
	int* p_i = &id;				//*pd = 19 is vaild;	
	const int* pt = p_i;		//*pt = 18 is invaild;

	//compare the two cases
	int sage = 20;
	const int *p_s = &sage;
	int* const finger = &sage;

	return 0;
}
