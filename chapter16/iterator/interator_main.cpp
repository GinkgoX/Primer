#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Review
{
	string title;
	int rating;
};

bool fillReview(Review &r);
void showReview(const Review &r);

int main()
{
	vector<Review> books;
	Review temp;
	while(fillReview(temp))
	{
		books.push_back(temp);
	}
	int num = books.size();
	if(num > 0)
	{
		for(int i = 0;i < num; i++)
		{
			showReview(books[i]);
		}
		vector<Review>::iterator pr;
		cout << "# Iterator test method # " << endl;
		for(pr = books.begin(); pr != books.end(); pr++)
		{
			showReview(*pr);
		}
		
		vector<Review> oldlList(books);
		if(num > 3)
		{
			books.erase(books.begin() + 1, books.begin() + 3);
		}
		
		cout << "# After rease book[1] nad book[2] # " << endl;
		for(pr = books.begin(); pr != books.end(); pr++)
		{
			showReview(*pr);
		}
		
		cout << "# After insert oldlList[1] into books first index " << endl;
		books.insert(books.begin(), oldlList.begin() + 1, oldlList.begin() + 2);
		for(pr = books.begin(); pr != books.end(); pr++)
		{
			showReview(*pr);
		}
		
		books.swap(oldlList);
		cout << "# Swap test method #" << endl;
		for(pr = books.begin(); pr != books.end(); pr++)
		{
			showReview(*pr);
		}
	}
	else
	{
		cout << "Nothing received ! " << endl;
	}
	cout << "done . " << endl;
	return 0;
}

bool fillReview(Review &r)
{
	cout << "Enter the book title : ";
	getline(cin, r.title);
	if(r.title == "quit")
	{
		return false;
	}
	cout << "Enter the book rating : ";
	cin >> r.rating;
	if(!cin)
	{
		return false;
	}
	cin.get();
	return true;
}

void showReview(const Review &r)
{
	cout << r.rating << "\t" << r.title << "\t" << endl;
}

