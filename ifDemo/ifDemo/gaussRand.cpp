/*
#include<iostream>
#include<cstdlib>
#include<ctime>
#define random(a, b) (rand()%(b - a + 1) + a) //generate the random number in [a, b]

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int rand_num = 0;
	int temp;
	rand_num = random(1, 100);
	cout << "Guess what number my brain has generated :" <<endl;
	cin >> temp;
	do
	{
		if (rand_num < temp)
		{
			cout << "	Your answer is too large " << endl;
		}
		else if (rand_num > temp)
		{
			cout << "	Your answer is too small " << endl;
		}
		else
		{
			cout << "good game, well done !" << endl;
		}
		cin >> temp;
	} while (rand_num != temp);
	cout << "good game, well done !" << endl;
	return 0;
}
*/

