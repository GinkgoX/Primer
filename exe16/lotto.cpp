#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>

using namespace std;

void show(int n){ cout << n << " ";};
vector<int> lotto(int max, int n);

int main()
{
	srand(time(0));
	vector<int> winner;
	winner = lotto(51, 6);
	for_each(winner.begin(), winner.end(), show);
	cout << endl;
	cout << "done . " << endl;
	return 0;
}

vector<int> lotto(int max, int n)
{
	vector<int> temp;
	vector<int> result;
	for(int i = 0; i < max; ++i)
	{
		temp.push_back(i + 1);
	}
	for(int i = 0; i < n; ++i)
	{
		random_shuffle(temp.begin(), temp.end());
		result.push_back(*temp.begin());
	}
	sort(result.begin(), result.end());
	return result;
}
