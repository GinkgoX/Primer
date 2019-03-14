#include<iostream>
#include<fstream>		//contains the ofstream class
#include<string>
#include<iomanip>		//contains the getchar() function to eliminate the Enter key

using namespace std;

struct Book {
	string name;
	string author;
	int pub_year;
	double price;
};

int main()
{
	int n;
	ofstream outFile;				//create the ofstream object named outFile
	outFile.open("book.txt");		//write the text into book.txt

	cout << "Enter the number of catalogies you want to save: ";
	cin >> n;
	Book* book = new Book[n];		//init the n object of book class.
	for (int i = 0;i < n; ++i)
	{
		cout << "The book name: ";
		getchar();
		getline(cin,book[i].name);
		cout << "The author name: ";
		getchar();
		getline(cin, book[i].author);
		cout << "The publication year: ";
		cin >> book[i].pub_year;
		cout << "The price: ";
		cin >> book[i].price;
	}
	for (int i = 0; i < n; ++i)
	{
		outFile << "The book name: " << book[i].name << endl;
		outFile << "The author name: " << book[i].author << endl;
		outFile << "The publication year: " << book[i].pub_year << endl;
		outFile << "The price: " << fixed << setprecision(2) << book[i].price << endl;
	}
	delete[] book;
	outFile.close();
	return 0;
}
