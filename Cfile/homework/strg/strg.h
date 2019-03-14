#include<iostream>

#ifndef STRG_H_
#define STRG_H_
class String
{
private:
	char *str;
	int len;
	static const int CLIMIT = 80;
public:
	String();
	String(const String &s);
	String(const char *c);
	~String();
	
	int has(char c)const;
	void stringlow();
	void stringup();
	
	String operator+(const String &s)const;
	String & operator=(const char *c);
	String & operator=(const String &s);
	
	friend bool operator<(const String &s1, const String &s2);
	friend bool operator>(const String &s1, const String &s2);
	friend bool operator==(const String &s1, const String &s2);
	friend String operator+(const char *c, const String &s);
	friend std::ostream & operator<<(std::ostream &os, const String &s);
	friend std::istream & operator>>(std::istream &is, String &s);
};
#endif

