#include<iostream>
using std::cin;
using std::cout;
using std::endl;

template<typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T &t):item(t){ct++;};
	~HasFriend(){ct--;};
	friend void count();
	friend void report(HasFriend<T> &hf);
};

template<typename T>
int HasFriend<T>::ct = 0;
void count()
{
	cout << "int count : " << HasFriend<int>::ct << " , ";
	cout << "double count : " << HasFriend<double>::ct << " . \n";
}

void report(HasFriend<int> &hf)
{
	cout << "HasFriend<int> : " << hf.item << endl;
}

void report(HasFriend<double> &hf)
{
	cout << "HasFriend<double> : " << hf.item << endl;
}

int main()
{
	cout << "No object declared : " << endl;
	count();
	
	HasFriend<int>hfi(10);
	cout << "After hfi declared : " << endl;
	count();
	HasFriend<int>hfi1(20);
	cout << "After hfi1 declared : " << endl;
	count();
	
	HasFriend<double>hfd(0.50);
	cout << "After hfd declared : " << endl;
	count();
	HasFriend<double>hfd1(1.50);
	cout << "After hfd1 declared : " << endl;
	count();
	
	report(hfi);
	report(hfi1);
	report(hfd);
	report(hfd1);
	
	cout << "done . " << endl;
	return 0;
}





