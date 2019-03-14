#include<iostream>
#include<valarray>
#include<cstdlib>

using namespace std;

typedef valarray<int> vint;
const int SIZE = 12;

void show(const vint &v, int cols);

int main()
{
	vint valint(SIZE);
	
	for(int i = 0; i < SIZE; i++)
	{
		valint[i] = rand() % 10;
	}
	
	cout << "# Original array #" << endl;
	show(valint, 3);
	
	cout << "# Second colume #" << endl;
	vint vcol(valint[slice(1, 4, 3)]);
	show(vcol, 1);
	
	cout << "# Second row #" << endl;
	vint vrow(valint[slice(3, 3, 1)]);
	show(vrow, 3);
	
	cout << "# set last colume to 10 #" << endl;
	valint[slice(2, 4, 3)] = 10;
	show(valint, 3);
	
	cout << "# first colume to sum of next two #" << endl;
	valint[slice(0, 4, 3)] = vint(valint[slice(1, 4, 3)]) + vint(valint[slice(2,4, 3)]);
	show(valint, 3);
	
	cout << "done. " << endl;
	return 0;
}


void show(const vint &v, int cols)
{
	int lim = v.size();
	for(int i = 0; i < lim; i++)
	{
		cout.width(3);
		cout << v[i];
		if(i % cols == cols -1)
		{
			cout << endl;
		}
		else
		{
			cout << " ";
		}
	}
	if(lim % cols != 0)
	{
		cout << endl;
	}
}

