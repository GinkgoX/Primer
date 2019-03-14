#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct Review
{
	string title;
	int rating;
};

bool operator<(const Review &r1, const Review &r2);
bool worseThan(const Review &r1, const Review &r2);
bool fillReview(Review &r);
void showReview(const Review &r);

int main()
{
	vector<Review>books;
	Review temp;
	while(fillReview(temp))
	{
		books.push_back(temp);
	}
	int num = books.size();
	if(num > 0)
	{
		vector<Review>::iterator pr;
		cout << "# for_each test method # " << endl;
		for_each(books.begin(), books.end(), showReview);
		
		sort(books.begin(), books.end());
		cout << "# Sort by Title # " << endl;
		for_each(books.begin(), books.end(), showReview);
		
		sort(books.begin(), books.end(), worseThan);
		cout << "# Sort by rating # " << endl;
		for_each(books.begin(), books.end(), showReview);
		
		random_shuffle(books.begin(), books.end());
		cout << "# Random shuffle # " << endl;
		for_each(books.begin(), books.end(), showReview);
	}	
	else
	{
		cout << "Nothing received . " << endl;
	}
	return 0;
}

bool operator<(const Review &r1, const Review &r2)
{
	if(r1.title < r2.title)
	{
		return true;
	}
	else if((r1.title == r2.title) && (r1.rating < r2.rating))
	{
		return false;
	}
	else
	{
		return false;
	}
}

bool worseThan(const Review &r1, const Review &r2)
{
	if(r1.rating < r2.rating)
	{
		return true;
	}
	else
		return false;
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
	cin.get();
	return true;	                                                                            
}

void showReview(const Review &r)
{
	cout << r.rating << "\t" << r.title << endl;
}
