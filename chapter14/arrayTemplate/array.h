#ifndef ARRAY_H_
#define ARRAY_H_

template<class Type, int n>
class Array
{
private:
	Type arr[n];
public:
	Array(){};
	explicit Array(const Type &t);
	virtual Type & operator[](int i);
	virtual Type operator[](int i)const;
};

template<class Type, int n>
Array<Type, n>::Array(const Type &t)
{
	for(int i = 0; i < n; i++)
	{
		arr[i] = t;
	}
}

template<class Type, int n>
Type & Array<Type, n>::operator[](int i)
{
	if(i < 0 || i >= n)
	{
		std::cerr << "Error in array limit : " << i << " is out of range . \n";
	}
	return arr[i];
}

template<class Type, int n>
Type Array<Type, n>::operator[](int i)const
{
	if(i < 0 || i >= n)
	{
		std::cerr << "Error in array limit : " << i << " is out of range . \n";
	}
	return arr[i];
}
#endif
