#include<iostream>
#include<cctype>
using namespace std;

int main()
{
	char ch;
	int ch1,ch2;
	ch1 = ch2 = 0;
	while ((ch = cin.get()) != '$')
	{
		//cout << ch;
		ch1++;
		//ch2 = isalnum(ch);
		//ch2 = isalpha(ch);
		ch2 = iscntrl(ch2);
		cout << ch2 <<endl;
		/*switch (ch2)
		{
		case 0: cout << " This is a space \n";
			break;
		case 1: cout << " This is a \n";
			break;
		case 2: cout << " This is a character \n";
			break;
		case 3: cout << " This is a balabala \n";
			break;
		default:
			cout << " This is a number \n";
			break;
		}*/
	}
	cout << "\n CH1= " << ch1 << endl;
	return 0;
}




