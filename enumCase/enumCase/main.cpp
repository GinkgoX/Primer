#include<iostream>

using namespace std;

enum {red, orange, yellow, green, bule, indigo, violet};

int main()
{
	int color;
	int i = 0;
	cout << "Enter the color level in 0 ~ 6: ";
	cin >> color;
	while (color >= red && color <= violet && i <= 3)
	{
		i++;
		switch (color)
		{
		case red:
			cout << "Her lips are red ! \n";
			break;
		case orange:
			cout << "Her hair is orange ! \n";
			break;
		case yellow:
			cout << "Her shoses are yellow !\n ";
			break;
		case green:
			cout << "Her nails are green ! \n";
			break;
		case bule:
			cout << "Her sweatsuit is bule ! \n";
			break;
		case indigo:
			cout << "Her mood is indigo ! \n";
			break;
		case violet:
			cout << "Her eyes are violet ! \n";
			break;
		default:
			cout << "Your order if out of my range !";
		}
		cout << "Enter the color level again: ";
		cin >> color;
	}
	cout << "Bye \n";
	return 0;
}
