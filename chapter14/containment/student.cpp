#include"student.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::istream;

ostream & Student::aout(ostream &os)const
{
	int limit = scores.size();
	if(limit > 0)
	{
		int i;
		for(i = 0; i < limit; i++)
		{
			os << scores[i] << " ";
			if(i % 5 == 4)
			{
				os << endl;
			}
			
		}
		if(i % 5 != 0)
		{
			os << endl;
		}
	}
	else
	{
		os << "empty array . " << endl;
	}
	return os;
}

Student::Student():name("Null"), scores()
{

}

Student::Student(const string &s):name(s),scores()
{

}

Student::Student(int n):name("Null"),scores(n)
{

}

Student::Student(const string &s, int n):name(s),scores(n)
{

}

Student::Student(const string &s, const adouble &sc):name(s),scores(sc)
{

}

Student::Student(const char *nm, const double *sc, int n):name(nm),scores(sc, n)
{

}

Student::~Student()
{

}

double Student::average()const
{
	if(scores.size() > 0)
	{
		return scores.sum() / scores.size();
	}
	else
	{
		return 0;
	}
}

const string & Student::getName()const
{
	return name;
}

double & Student::operator[](int i)
{
	return scores[i];
}

double Student::operator[](int i)const
{
	return scores[i];
}

istream & operator>>(istream &is, Student &stu)
{
	is >> stu.name;
	return is;
}

istream & getline(istream &is, Student &stu)
{
	getline(is, stu.name);
	return is;
}

ostream & operator<<(ostream &os, const Student &stu)
{
	os << "Scores for " << stu.name << ": \n";
	stu.aout(os);
	return os;
}


