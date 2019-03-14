#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

typedef int Key;
typedef pair<const Key, string> Pair;
typedef multimap<Key, string> MapCode;

int main()
{
	MapCode codes;
	
	codes.insert(Pair(415, "San Francisco"));
	codes.insert(Pair(510, "Oakland"));
	codes.insert(Pair(718, "Brooklyn"));
	codes.insert(Pair(718, "Staten Island"));
	codes.insert(Pair(415, "San Rafael"));
	codes.insert(Pair(510, "Berkeley"));
	
	cout << "Num of cities with area code 415 : " << codes.count(415) << endl;
	cout << "Num of cities with area code 510 : " << codes.count(510) << endl;
	cout << "Num of cities with area code 718 : " << codes.count(718) << endl;
	
	cout << "# Area Code #" << endl;
	MapCode::iterator it;
	for(it = codes.begin(); it != codes.end(); ++it)
	{
		cout << "	" << (*it).first << "	" << (*it).second << endl;
	}
	
	cout << "# City with area code 718 #" << endl;
	pair<MapCode::iterator, MapCode::iterator> Range = codes.equal_range(718);
	for(it = Range.first; it != Range.second; ++it)
	{
		cout << (*it).second << endl;
	}
	
	return 0;
}


