#include<iostream>
using std::cout;
using std::endl;

template<typename T>void count();
template<typename T>void report(T &t);

template<typename TT>
class HasFriendT
{
private:
	TT item;
	static int ct;
public:
	HasFriendT(const TT &tt):item(tt){ct++;};
	~HasFriendT(){ct--;};
	friend void count<TT>();
	friend void report<>(HasFriendT<TT> &tt);
};

template<typename T>
int HasFriendT<T>::ct = 0; 

template<typename T>
void count()
{
	cout << "Template size : " << sizeof(HasFriendT<T>) << " ; ";
	cout << "Template cout() : " << HasFriendT<T>::ct << endl;
}

template<typename T>
void report(T &hf)
{
	cout << hf.item << endl;
}

int main()
{
	count<int>();
	HasFriendT<int>hfi(10);
	HasFriendT<int>hfi1(20);
	HasFriendT<double>hfd(0.05);
	HasFriendT<double>hfd1(1.05);
	report(hfi);
	report(hfi1);
	report(hfd);
	report(hfd1);
	
	cout << "count<int> : " ;
	count<int>();
	cout << "count<double> : ";
	count<double>();
	
	return 0;
}

