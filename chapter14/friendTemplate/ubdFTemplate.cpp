#include<iostream>
using std::cout;
using std::endl;

template<typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T &t):item(t){};
	template<typename T1, typename T2> friend void show2(T1 &t1, T2 &t2);
};

template<typename T1, typename T2> void show2(T1 &t1, T2 &t2) 
{
	cout << t1.item << " , " << t2.item << endl;
}

int main()
{
	ManyFriend<int>mfi(10);
	ManyFriend<int>mfi1(20);
	ManyFriend<double>mfd(0.05);
	ManyFriend<double>mfd1(1.05);

	cout << "mfi, mfi1 : ";
	show2(mfi, mfi1);
	cout << "mfd, mfd1 : ";
	show2(mfd, mfd1);
	cout << "mfi, mfd : ";
	show2(mfi, mfd);
	cout << "mfd1, mfi1 : ";
	show2(mfd1, mfi1);

	cout << "done . " << endl;
	return 0;
}
