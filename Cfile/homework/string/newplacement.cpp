#include<iostream>
#include<string>
#include<new>

using namespace std;
const int BUF = 512;

class Test
{
private:
	string words;
	int number;
public:
	Test(const string &s = "Test", int n = 0)
	{
		words = s;
		number = n;
		cout << words << "constructed !" << endl;
	}
	~Test()
	{
		cout << words << "destoried !" << endl;
	}
	void show()const
	{
		cout << words << " , " << number << endl;
	}
};


int main()
{
	char *buffer = new char[BUF];
	Test *pc1, *pc2;
	pc1 = new(buffer)Test;
	pc2 = new Test("Heap1", 20);
	cout << "Memory block address : "
	return 0;
}








