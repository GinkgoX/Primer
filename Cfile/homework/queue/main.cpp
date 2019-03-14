#include<iostream>
#include<cstdlib>
#include<ctime>
#include"queue.h"

using namespace std;

const int UNIT = 60;

bool newcustomer(double x);

int main()
{
	srand(time(0));
	cout << "Case study: Band of Heather Automatic Teller \n";
	cout << "Enter the maximum size of queue : ";
	int qs;
	cin >> qs;
	Queue line(qs);
	
	cout << "Enter the number of simulation hours : ";
	int hours;
	cin >> hours;
	
	long cycle_time = UNIT * hours;
	
	cout << "Enter the average number of customer per hour : ";
	double perhour;
	cin >> perhour;
	double min_per_custom = UNIT / perhour;
	
	Item temp;
	long turnaway = 0;
	long customers = 0;
	long served = 0;
	long sumline = 0;
	int wait_time = 0;
	long line_wait = 0;
	for(int cycle = 0; cycle < cycle_time; cycle++)
	{
		if(newcustomer(min_per_custom))
		{
			if(line.isfull())
			{
				turnaway++;
			}
			else
			{
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}	
		}
		if( (wait_time <= 0) && (!line.isempty()) )
		{
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if(wait_time > 0)
		{
			wait_time--;
		}
		sumline += line.queuecount();
	}
	
	if(customers > 0)
	{
		cout << "Customer accepted : " << customers << endl;
		cout << "Customer served : " << served << endl;
		cout << "Customer turnaway : " << turnaway << endl;
		cout << "average queue size : ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << sumline / cycle_time << endl;
		cout << "average wait time : " << (double)line_wait / served << " minutes ." << endl;
	}
	else
	{
		cout << "No customers ! \n";
	}
	
	cout << "done . \n";
	return 0;
}

bool newcustomer(double x)
{
	return(rand()*x / RAND_MAX < 1);
}

