/*
#include<iostream>

const int Arsize = 8;

int sum_arr(int array[], int n);

int main()
{
	int cookie[Arsize] = {1,2,4,8,16,32,64,128};
	std::cout << "cookie address : " << cookie << std::endl;		//check the address of cookie;
	std::cout << "array size : " << sizeof(cookie) << std::endl;
	int sum = sum_arr(cookie, Arsize);
	std::cout << "Total cookies : " << sum << std::endl;
	sum = sum_arr(cookie, 3);
	std::cout << "The first 3 cookies sum : " << sum << std::endl;
	sum = sum_arr(cookie + 4, 4);
	std::cout << "The last 4 cookies sum : " << sum << std::endl;
	return 0;
}

int sum_arr(int array[], int n)
{
	std::cout << "array address : " << array << std::endl;			//check the address of array;
	std::cout << "array size : " << sizeof(array) << std::endl;
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += array[i];
	}
	return total;
}
*/
