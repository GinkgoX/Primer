#include"student.h"

using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

ostream & Student::aout(ostream &os)const
{
	int i;
	int limit = adouble::size();
	if(limit > 0)
	{
		for(i = 0; i < limit; i++)
		{
			os << adouble::operator[](i) << " ";
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
		os << "empty scores ." << endl;
	}
	return os;
}

Student::Student():string("Null"),adouble()
{

}

Student::Student(const string &nm):string(nm),adouble()
{

}

Student::Student(int n):string("Null"),adouble(n)
{

}

Student::Student(const string &nm, int n):string(nm),adouble(n)
{

}

Student::Student(const string &nm, const adouble &sc):string(nm),adouble(sc)
{

}

Student::Student(const char *nm, const double *sc, int n):string(nm),adouble(sc, n)
{

}

Student::~Student()
{

}

const string & Student::getName()const
{
	return (const string &)*this;
}

double Student::average()const
{
	if(adouble::size() > 0)
	{
		return adouble::sum() / adouble::size();
	}
	else
	{
		return 0;
	}
}

double & Student::operator[](int i)
{
	return adouble::operator[](i);
}

double Student::operator[](int i)const
{
	return adouble::operator[](i);
}

istream & getline(istream &is, const Student &stu)
{
	getline(is, (string &)stu);
	return is;
}

istream & operator>>(istream &is, Student &stu)
{
	is >> (string &)stu;
	return is;
}

ostream & operator<<(ostream &os, const Student &stu)
{
	os << "Scores for " << (const string &)stu << " :\n";
	stu.aout(os);
	return os;
}

