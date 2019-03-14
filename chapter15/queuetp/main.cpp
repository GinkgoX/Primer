#include<iostream>
#include<string>
#include"queuetp.h"

using namespace std;

int main()
{
	Queue<string> qs(5);
	string temp;
	
	while(!qs.isfull())
	{
		cout << "Please enter your name, and you will be served in order of arrival . " << endl;
		cout << "Name : ";
		getline(cin, temp);
		qs.enqueue(temp);
	}
	
	cout << "Now, the queue is full.Processing begins : \n";
	while(!qs.isempty())
	{
		qs.dequeue(temp);
		cout << "Now processing " << temp << " ... " << endl;
	}
		
	return 0;
}

