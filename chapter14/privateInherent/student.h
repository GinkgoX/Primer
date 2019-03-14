#ifndef STUDENT_H_
#define STUDENT_H_

#include<iostream>
#include<valarray>
#include<string>

class Student:private std::string, private std::valarray<double>
{
private:
	typedef std::valarray<double> adouble;
	std::ostream & aout(std::ostream &os)const;
public:
	Student();
	Student(const std::string &nm);
	Student(int n);
	Student(const std::string &nm, int n);
	Student(const std::string &nm, const adouble &sc);
	Student(const char *nm, const double *sc, int n);
	~Student();
	const std::string & getName()const;
	double average()const;
	double & operator[](int i);
	double operator[](int i)const;
	friend std::istream & getline(std::istream &is, const Student &stu);
	friend std::istream & operator>>(std::istream &is, Student &stu);
	friend std::ostream & operator<<(std::ostream &os, const Student &stu);
};

#endif

