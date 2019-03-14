#ifndef STUDENT_H_
#define STUDENT_H_

#include<iostream>
#include<cstring>
#include<valarray>

class Student
{
private:
	typedef std::valarray<double> adouble;
	std::string name;
	adouble scores;
	std::ostream & aout(std::ostream &os)const;
public:
	Student();
	Student(const std::string &s);
	explicit Student(int n);
	Student(const std::string &s, int n);
	Student(const std::string &s, const adouble &sc);
	Student(const char *nm, const double *sc, int n);
	~Student();
	double average()const;
	const std::string & getName()const;
	double & operator[](int i);
	double operator[](int i)const;
	friend std::istream & operator>>(std::istream &is, Student &stu);
	friend std::istream & getline(std::istream &is, Student &stu);
	friend std::ostream & operator<<(std::ostream &os, const Student &stu);
};

#endif









