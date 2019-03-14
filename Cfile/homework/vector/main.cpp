#include<iostream>
#include<fstream>
#include<cstdlib>			//include rand() / srand() prototype 
#include<ctime>				//include time() prototype
#include"vect.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	ofstream fout;
	fout.open("record.txt");
	Vector result(0.0, 0.0);
	Vector step;
	unsigned long steps = 0;
	double direction;
	double target;
	double dstep;
	int N;
	unsigned long max = 0;
	unsigned long min = 100;
	double avg;
	srand(time(0));
	
	cout << "Enter N times to test:";
	cin >> N;
	for(int i = 0; i < N; ++i)
	{
		cout << "Enter the target diatance (q or Q to quit) : ";
		cin >> target;
		cout << "Enter the step length: ";
		if(!(cin >> dstep))
		{
			break;
		}
		fout << "Target distance : " << target << " , and step length : " << dstep << endl;
		while(result.r_val() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, 'p');
			result = result + step;
			fout << steps << "# location :"  << result << endl;
			steps++;
		}
		max = (max < steps) ? steps : max;
		min = (min > steps) ? steps : min;
		avg += steps;
		result.polar();
		steps = 0;
		result.reset(0.0, 0.0);
	}
	avg /= N;
	cout << "max = " << max << " , min = " << min << " , avg = " << avg << endl;
	cout << "Bye ." << endl;
	cout << "max = " << max << " , min = " << min << " , avg = " << avg << endl;
	cout << "Bye ." << endl;
	fout.close();
	cin.clear();
	while(cin.get() != '\n')
	{
		continue;
	}
	return 0;
}

