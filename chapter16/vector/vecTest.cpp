#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int NUM = 5;

int main()
{
	vector<int> ratings(NUM);
	vector<string> titles(NUM);
	cout << "You will enter " << NUM << " book titles and the ratings(0 - 10) !" << endl;
	for(int i = 0; i < NUM; i++)
	{
		cout << "Enter the title : ";
		getline(cin, titles[i]);
		cout << "Enter the rating(0 - 10) : ";
		cin >> ratings[i];
		cin.get(); 
	}
	
	cout << "Now, your enter information as follows : " << endl;
	for(int i = 0; i < NUM;i++)
	{
		cout << ratings[i] << "\t" << titles[i] << endl;
	}
	return 0;
}



