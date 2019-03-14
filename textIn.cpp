#include<iostream>

using namespace std;

int main(){
	char ch;
	int count = 0;
	cout << "Enter a series of words(end with #):";
	cin.get(ch);
	while(ch != '#'){
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << "characters are recored !";
	return 0;
}












