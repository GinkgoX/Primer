#include<iostream>
#include"dma.h"

using namespace std;

int main()
{
	baseDMA bd("java", 4);
	lacksDMA ld("green", "C++", 3);
	hasDMA hd("OOP", "python", 2);
	cout << bd << endl;
	cout << ld << endl;
	cout << hd << endl;
	
	lacksDMA ld2(ld);
	cout << ld2 << endl;
	
	hasDMA hd2;
	hd2 = hd;
	cout << hd2 << endl;
	return 0;
}


