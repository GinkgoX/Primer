#include<iostream>
#include"student.h"

using namespace std;

void set(Student &stu, int n);

const int pupils = 3;
const int quizzes = 5;

int main()
{
	Student stu[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
	for(int i = 0; i < pupils;i++)
	{
		set(stu[i], quizzes);
	}
	cout << "\nStudent List : " << endl;
	for(int i = 0; i < pupils;i++)
	{
		cout << stu[i].getName() << endl;
	}
	cout << "\nResult : ";
	for(int i = 0;i < pupils;i++)
	{
		cout << endl << stu[i];
		cout << "Average : " << stu[i].average() << endl;
	}
	cout << "Done . " << endl;
	return 0;
}

void set(Student &stu, int n)
{
	cout << "Please enter the student's name : ";
	getline(cin, stu);
	cout << "Please enter " << n << " quizzes scores : \n";
	for(int i = 0;i < n;i++)
	{
		cin >> stu[i];
	}
	while(cin.get() != '\n')
	{
		continue;
	}
}

