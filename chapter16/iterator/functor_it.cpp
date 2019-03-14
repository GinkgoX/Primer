#include<iostream>
#include<list>
#include<iterator>

using namespace std;

template<class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T &t):cutoff(t){};
	bool operator()(const T &v){return v > cutoff;};
};

int main()
{
	TooBig<int> f100(100);
	list<int> la;
	list<int> lb;
	int vals[10] = {20, 123, 231, 342, 12, 135, 93, 201, 164, 100};
	la.insert(la.begin(), vals, vals + 10);
	lb.insert(lb.begin(), vals, vals + 10);
	ostream_iterator<int, char> out_iter(cout, " ");
	
	cout << "# list info #" << endl;
	copy(la.begin(), la.end(), out_iter);
	cout << endl;
	copy(lb.begin(), lb.end(), out_iter);
	cout << endl; 
	
	cout << "# functor test method #" << endl;
	la.remove_if(f100);
	lb.remove_if(TooBig<int>(200));
	copy(la.begin(), la.end(), out_iter);
	cout << endl;
	copy(lb.begin(), lb.end(), out_iter);
	cout << endl;
	return 0;
}

