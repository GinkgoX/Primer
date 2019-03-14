#include<algorithm>
#include<iostream>
#include<iterator>
#include<string>
#include<set>

using namespace std;

const int N = 6;

int main()
{
	string s1[N] = {"buffoon", "thinkers", "for", "heavy", "can", "for"};
	string s2[N] = {"metal", "any", "food", "elegant", "deliver", "for"};
	
	set<string> A(s1, s1 + N);
	set<string> B(s2, s2 + N);
	ostream_iterator<string, char> out_iter(cout, " ");
	
	cout << "# set A #" << endl;
	copy(A.begin(), A.end(), out_iter);
	cout << endl;
	
	cout << "# set B #" << endl;
	copy(B.begin(), B.end(), out_iter);
	cout << endl;
	
	cout << "# union of A and B #" << endl;
	set_union(A.begin(), A.end(), B.begin(), B.end(), out_iter);
	cout << endl;
	
	cout << "# intersection of A and B #" << endl;
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out_iter);
	cout << endl;
	
	cout << "# difference of A and B #" << endl;
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out_iter);
	cout << endl;
	
	cout << "# C = A union B #" << endl;
	set<string> C;
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string> >(C, C.begin()));
	copy(C.begin(), C.end(), out_iter);
	cout << endl;
	
	cout << "# inset a string to C #" << endl;
	string s3 = "gruny";
	C.insert(s3);
	copy(C.begin(), C.end(), out_iter);
	cout << endl;
	
	cout << "# show a range #" << endl;
	copy(C.lower_bound("ghost"), C.upper_bound("hpook"), out_iter);
	cout << endl;
	
	return 0;
}







