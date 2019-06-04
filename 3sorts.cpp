#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;
using namespace System;

void swap(int &a, int &b)
{
	int aux;
	aux = a;
	a = b;
	b = aux;
}
int main()
{
	int aux;
	int n=10;
	Random x;
	vector<int>a;
	for (int i = 0; i < n; i++)
	{
		a.push_back(x.Next(0,50));
	}
	for (int i = 0; i < n; i++)
	{
		cout << a.at(i)<<' ';
	}
	//Bubble Sort
	/*for (int i = 0; i < 20; i++)
	{
		for (int j = i + 1; j < 21; j++)
		{
			if (a.at(i) > a.at(j))
			{
				aux = a.at(i);
				a.at(i) = a.at(j);
				a.at(j) = aux;
			}
		}
	}*/
	cout << endl;
	// Selection Sort
	/*int aj;
	for (int i = 0; i < 20; i++)
	{
		int min = a.at(i);
		for (int j = i+1; j < 21; j++)
		{
			if (a.at(j) < min)
			{
				min = a.at(j);
				aj = j;
			}
		}
		swap(a.at(i),a.at(aj));

	}*/
//Insertion Sort
	for (int i = 0; i < n; i++)
	{	
		int j = i;
		while (j > 0 && a.at(j - 1) > a.at(j))
		{
			swap(a.at(j - 1), a.at(j));
			j--;
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a.at(i) << ' ';
	}

	_getch();
	return 0;
}