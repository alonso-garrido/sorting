#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "HashEntry.h"
#include "CAlumno.h"
using namespace std;
using namespace System;
template <class T>

class HashMap
{
private:
	HashEntry<T>**table;
	HashEntry<T>**ntable;
	int bsize;
	int taken = 0;
	int step = 1;
public:
	HashMap()
	{
		bsize = 4;
		table = new HashEntry<T>*[bsize];
		for (int i = 0; i < bsize; i++)
		{
			table[i] = NULL;
		}
		ntable = table;
	}
	~HashMap()
	{
		for (int i = 0; i < bsize; i++)
		{
			if (table[i] != NULL)
			{
				delete table[i];
			}
		}
		delete[] table;
	}
	int CreateKey(string pname)
	{
		unsigned int suma = 0;
		for (int i = 0; i < pname.size(); i++)
		{
			suma += Convert::ToInt32(pname.at(i));
		}
		return suma;
	}
	int Hash(int key)
	{
		int hash = key % bsize;
		return hash;
	}
	int SondeoLineal(int hash, int pstep)
	{
		int nhash;
		nhash = (hash + pstep) % bsize;
		return nhash;
	}
	void insert(string name, T value)
	{

		if (((float)taken / (float)bsize) >= 0.60)
		{
			Rehash();
		}
		int pos = Hash(CreateKey(name));
		while (table[pos] != NULL)
		{
			pos = SondeoLineal(pos, step);
			step++;
		}
		step = 1;
		table[pos] = new HashEntry<T>(CreateKey(name), value);
		taken++;
	}
	void ninsert(string name, T value)
	{
		int npos = Hash(CreateKey(name));
		while (ntable[npos] != NULL)
		{
			npos = SondeoLineal(npos, step);
			step++;
		}
		step = 1;
		ntable[npos] = new HashEntry<T>(CreateKey(name), value);
		taken++;
	}
	void Rehash()
	{
		cout << endl << ":::REHASHING:::" << endl;
		taken = 0;
		bsize = bsize * 2;
		ntable = new HashEntry<T>*[bsize];
		for (int i = 0; i < bsize; i++)
		{
			ntable[i] = NULL;
		}
		for (int i = 0; i < bsize/2; i++)
		{
			if (table[i]->getvalue() != nullptr)
			{
				T aux = table[i]->getvalue();
				table[i] = NULL;
				ninsert(aux->getnombre(), aux);
				cout << endl;
				nget(aux->getnombre())->Print();
			}
		}
		table = ntable;
		for (int i = 0; i < bsize; i++)
		{
			delete ntable[i];
		}
		delete[] ntable;
		//delete[] table;
		//table = new HashEntry<T>*[bsize];
		//for (int i = 0; i < bsize; i++)
		//{
		//	table[i] = ntable[i];
		//	delete ntable[i];
		//}
		//delete[]ntable;
	}
	T get(string name)
	{
		int hash = Hash(CreateKey(name));
		if (table[hash] == NULL)
		{
			T aux = new CAlumno("vacio", "vacio", "vacio", 0);
			return aux;
		}
		else
		{
			while (table[hash]->getvalue()->getnombre() != name)
			{
				hash=SondeoLineal(hash, step);
				step++;
			}
			step = 1;
			return table[hash]->getvalue();
		}
	}
	T nget(string name)
	{
		int hash = Hash(CreateKey(name));
		if (ntable[hash] == NULL)
		{
			T aux = new CAlumno("vacio", "vacio", "vacio", 0);
			return aux;
		}
		else
		{
			while (ntable[hash]->getvalue()->getnombre() != name)
			{
				hash = SondeoLineal(hash, step);
				step++;
			}
			step = 1;
			return ntable[hash]->getvalue();
		}
	}
	
};
