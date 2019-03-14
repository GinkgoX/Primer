#include<iostream>
using std::ostream;
using std::istream;

#ifndef STRG_H_
#define STRG_H_
class String
{
private:
	char *str;
	int len;
	static int num_strngs;
	static const int CINLIM = 80;
public:
	String();
	String(const String &s);
	String(const char *c);
	~String();
	
	int length()const{return len;}
	String & operator=(const char *c);
	String & operator=(const String &s);
	String & operator+(const String &s);
	String & stringup();
	String & stringlow();
	int has(const char &c);
	char & operator[](int i);
	const char & operator[](int i)const;
	
	friend bool operator<(const String &s1, const String &s2);
	friend bool operator>(const String &s1, const String &s2);
	friend bool operator==(const String &s1, const String &s2);
	friend ostream & operator<<(ostream &os, const String &s);
	friend istream & operator>>(istream &is, String &s);
	
	static int count();
};

#endif

