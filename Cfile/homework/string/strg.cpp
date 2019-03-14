#include<cstring>
#include"strg.h"

using namespace std;

int String::num_strngs = 0;

int String::count()
{
	return num_strngs;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strngs++;
}

String::String(const String &s)
{
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
	num_strngs++;
}

String::String(const char *c)
{
	len = std::strlen(c);
	str = new char[len + 1];
	strcpy(str, c);
	num_strngs++;
}

String::~String()
{
	--num_strngs;
	delete[] str;
}

String & String::operator=(const String &s)
{
	if(this == &s)
	{
		return *this;
	}
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	strcpy(str, s.str);
	return *this;
}

String & String::operator=(const char *c)
{
	delete[] str;
	len = std::strlen(c);
	str = new char[len + 1];
	strcpy(str, c);
	return *this;
}

char & String::operator[](int i)
{
	return str[i];
}

const char & String::operator[](int i)const
{
	return str[i];
}

bool operator<(const String &s1, const String &s2)
{
	return (strcmp(s1.str, s2.str) < 0);
}

bool operator>(const String &s1, const String &s2)
{
	return s2.str < s1.str;
}

bool operator==(const String &s1, const String &s2)
{
	return (strcmp(s1.str, s2.str) == 0);
}

ostream & operator<<(ostream &os, const String &s)
{
	os << s.str;
	return os;
}

istream & operator>>(istream &is, String &s)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if(is)
	{
		s = temp;
	}
	while(is && is.get() != '\n')
	{
		continue;
	}
	return is;
}

