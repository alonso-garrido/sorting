#pragma once
#include <string>
using namespace std;
template<class T>

class HashEntry
{
private:
	T value;
	int key;
public:
	HashEntry(int pkey, T pvalue)
	{
		key = pkey;
		value = pvalue;
	}
	T getvalue()
	{
		return value;
	}
	int getkey()
	{
		return key;
	}
	~HashEntry()
	{
		key = 0;
		value = NULL;
	}
	template <class U> friend class HashMap;
};