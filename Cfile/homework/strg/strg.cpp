#include<cstring>
#include"strg.h"

using namespace std;

String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
}

String::String(const String &s)
{
	len = strlen(s.str);
	str = new char[len + 1];
	strcpy(str, s.str);
}

String::String(const char *c)
{
	len = strlen(c);
	str = new char[len + 1];
	strcpy(str, c);
}

String::~String()
{
	delete[] str;
}

int String::has(char c)const
{
	int num = 0;
	for(int i = 0; i < len; i++)
	{
		if(str[i] == c)
		{
			num++;
		}
	}
	return num;
}

void String::stringlow()
{
	for(int i = 0; i < len; i++)
	{
		str[i] = tolower(str[i]);
	}
}

void String::stringup()
{
	for(int i = 0; i < len; i++)
	{
		str[i] = toupper(str[i]);
	}
}

String String::operator+(const String &s)const
{
	String temp;
	temp.len = len + s.len;
	delete[] temp.str;
	temp.str = new char[temp.len + 1];
	strcpy(temp.str, str);
	strcat(temp.str, s.str);
	return temp;
}

String & String::operator=(const char *c)
{
	delete[] str;
	len = strlen(c);
	str = new char[len + 1];
	strcpy(str, c);
	return *this;
}

String & String::operator=(const String &s)
{
	delete[] str;
	len = strlen(s.str);
	str = new char[len + 1];
	strcpy(str, s.str);
	return *this;
}

bool operator<(const String &s1, const String &s2)
{
	return (strcmp(s1.str, s2.str) < 0);
}

bool operator>(const String &s1, const String &s2)
{
	return (s2.str < s1.str);
}

bool operator==(const String &s1, const String &s2)
{
	return (strcmp(s1.str, s2.str) == 0);
}

String operator+(const char *c, const String &s)
{
	String temp;
	delete[] temp.str;
	temp.len = strlen(c) + strlen(s.str);
	temp.str = new char[temp.len + 1];
	strcpy(temp.str, c);
	strcat(temp.str, s.str);
	return temp;
}

ostream & operator<<(ostream &os, const String &s)
{
	os << s.str;
	return os;
}

istream & operator>>(istream &is, String &s)
{
	char temp[String::CLIMIT];
	is.get(temp, String::CLIMIT);
	if(is)
	{
		s = temp;
	}
	while(is && (is.get()!= '\n'))
	{
		continue;
	}
	return is;
}
