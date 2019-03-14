#include<iostream>
#include"cow.h"

using namespace std;

int main()
{
	Cow c1;
	c1.showCow();
	
	Cow c2("wowo", "swimming", 20);
	c2.showCow();
	
	c1 = c2;
	c1.showCow();
	
	return 0;
}

