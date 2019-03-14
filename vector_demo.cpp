#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>  // greater<T>

using namespace std;

bool mask(int n);
template<class T>
void show(const char *s, const vector<T> &v);

int main()
{
	int a[] = {1, 2, 3, 4 ,5};
	vector<int> v1;
	show("v1", v1);
	for(int j = 0; j <= 5; ++j)
	{
		v1.push_back(j);
	}
	show("v1", v1);
	
	vector<int> v2(3, 7);
	show("v2", v2);
	
	vector<int>::iterator vec_iter = v1.begin() + 1;
	vector<int> v3(vec_iter, vec_iter + 2);
	show("v3", v3);
	v3.reserve(6);	//change the capacity
	show("v3", v3);
	
	vector<int> v4(v1);
	show("v4", v4);
	v4.resize(7);	// change the size and capacity
	show("v4", v4);
	v4.resize(3);
	show("v4", v4);
	v4.clear();
	show("v4", v4);
	v4.insert(v4.end(), v3[1]);
	v4.insert(v4.end(), v3.at(1));
	v4.insert(v4.end(), 2, 4);
	show("v4", v4);
	v4.insert(v4.end(), v1.begin(), v1.end() - 1);
	v4.erase(v4.end() - 2);
	v4.erase(v4.begin(), v4.begin() + 4);
	show("v4", v4);
	v4.assign(3, 8);
	show("v4", v4);
	v4.assign(a, a + 3);
	show("v4", v4);
	
	vector<int> v5(5);
	show("v5", v5);
	v5[1] = v5.at(3) = 9;
	show("v5", v5);
	
	vector<int>::reverse_iterator rev_iter;
	cout << "v4 reverse" << endl;
	cout << "v4 : " ;
	for(rev_iter = v4.rbegin(); rev_iter < v4.rend(); ++rev_iter)
	{
		cout << *rev_iter << " ";
	}
	cout << endl;
	
	v5[0] = 3;
	replace_if(v5.begin(), v5.end(), mask, 7);
	v5[0] = 3;
	v5[2] = v5[4] = 0;
	replace(v5.begin(), v5.end(), 0, 7);
	sort(v5.begin(), v5.end());
	show("v5", v5);
	sort(v5.begin(), v5.end(), greater<int>());
	show("v5", v5);
	v5.front() = 2;
	show("v5", v5);
	
	cout << "done . " << endl;
	return 0;
}

bool mask(int n)
{
	return n < 4;
}

template<class T>
void show(const char *s, const vector<T> &v)
{
	cout << s << " : ";
	typename vector<T>::const_iterator viter;
	for(viter = v.begin(); viter != v.end(); ++viter)
	{
		cout << *viter << " ";
	}
	cout << endl;
}
