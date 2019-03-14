#include<iostream>
#include<new>

using namespace std;

const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main()
{
	double *pd1, *pd2;
	pd1 = new double[N];
	pd2 = new(buffer) double[N];
	cout << "Calling new and placement new : \n";
	
	for(int i =0; i < N; i++)
	{
		pd2[i] = pd1[i] = 1000 + 20.0*i;
	}
	
	cout << "Buffer address : \n";
	cout << "# heap : " << pd1 << " #static : " << (void *)buffer << endl;
	cout << "Buffer contents: \n";
	for(int i = 0; i < N; i++)
	{
		cout << pd1[i] << " at  " << &pd1[i] << " ; ";
		cout << pd2[i] << "  at  " << &pd2[i] << endl;
	}
	
	cout << "\n Calling new and placement new twice : \n";
	double *pd3, *pd4;
	pd3 = new double[N];
	pd4 = new(buffer) double[N];
	for(int i = 0; i < N; i++)
	{
		pd4[i] = pd3[i] = 1000 + 20.0*i;
	}
	cout << "Buffer contents : \n";
	for(int i = 0; i < N; i++)
	{
		cout << pd3[i] << "  at  " << &pd3[i] << " ; ";
		cout << pd4[i] << "  at  " << &pd4[i] << endl;
	}
	cout << "\n Calling new and placement third time : \n";
	delete[] pd1;
	pd1 = new double[N];
	pd2 = new(buffer + N*sizeof(double)) double[N];
	for(int i = 0; i < N; i++)
	{
		pd2[i] = pd1[i] = 1000 + 20.0*i;
	}
	cout << "Buffer contents : \n";
	for(int i = 0; i < N; i++)
	{
		cout << pd1[i] << "  at  " << &pd1[i] << " ; ";
		cout << pd2[i] << "  at  " << &pd2[i] << endl;
	}
	delete[] pd1;
	delete[] pd3;
	return 0;
}










