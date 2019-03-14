#include<iostream>
#include<ctime>		//contains clock() function, clock_t type

using namespace std;

int main(){
	float secs;
	cout << "Enter a dalay time:";
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;
	clock_t start = clock();
	cout << "Starting ! \a\n";
	while(clock() - start < delay){	
	}
	cout << "Done \a\n";
	return 0;
}






