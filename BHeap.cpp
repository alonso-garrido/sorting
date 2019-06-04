#include <conio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class CAlumno
{
protected:
	string nombre;
	string codigo;
	int numero;
public:
	CAlumno(string pnombre, string pcodigo, int pnumero)
	{
		nombre = pnombre;
		codigo = pcodigo;
		numero = pnumero;
	}
	~CAlumno()
	{
		nombre = "";
		codigo = "";
		numero = 0;
	}
	string getnombre()
	{
		return nombre;
	}
	string getcodigo()
	{
		return codigo;
	}
	int getnumero()
	{
		return numero;
	}
	void Print()
	{
		cout << "Nombre: " << nombre << endl << "Codigo: " << codigo << endl << "Numero: " << numero << endl;
	}
	template <class U> friend class CBinaryHeap;
};

template <class T>
class CBinaryHeap
{
protected:
	vector<T>*heap;
	int taken;
public:
	CBinaryHeap()
	{
		taken = 0;
		heap = new vector<T>;
	}
	~CBinaryHeap()
	{
		taken = 0;
		heap->erase;
	}
	int Parent(int pos)
	{
		pos = (pos - 1) / 2;
		return pos;
	}
	int LChild(int pos)
	{
		pos = pos * 2 + 1;
		return pos;
	}
	int RChild(int pos)
	{
		pos = pos * 2 + 2;
		return pos;
	}
	void swap(T&a, T&b)
	{
		T aux;
		aux = a;
		a = b;
		b = aux;
	}
	void HeapifyUp(int i)
	{
		if (i != 0 && heap->at(i)->numero > heap->at(Parent(i))->numero)
		{
			swap(heap->at(i), heap->at(Parent(i)));
			i = Parent(i);
			HeapifyUp(i);
		}
	}
	void Insert(T v)
	{
		heap->push_back(v);
		int i = taken;
		HeapifyUp(i);
		taken++;
	}
	void hPrint()
	{
		ofstream archivaldo;
		archivaldo.open("archivoplano.txt", ios::trunc);
		if (archivaldo.is_open())
		{
			for (int i = 0; i < heap->size(); i++)
			{
				archivaldo << (heap->at(i)->getnombre()) << " ";
				archivaldo << (heap->at(i)->getcodigo()) << " ";
				archivaldo << (heap->at(i)->getnumero()) <<endl;
			}
		}
		archivaldo.close();
	}
	void Printerino()
	{
		for (int i = 0; i < heap->size(); i++)
		{
			heap->at(i)->Print();
		}
	}
	void Load()
	{
		vector<T>*aux= new vector<T>;
		ifstream archivaldo;
		archivaldo.open("archivoplano.txt", ios::in);
		if (archivaldo.is_open())
		{
			while (!archivaldo.eof())
			{
				string auxnom, auxcod;
				int auxnum;
				archivaldo >> auxnom >> auxcod >> auxnum;
				if (auxnom != "" && auxcod != "")
				{
					T auxalum = new CAlumno(auxnom, auxcod, auxnum);
					aux->push_back(auxalum);
				}
			}
		}
		heap = aux;
		archivaldo.close();
	}
	T Mayor(T a, T b)
	{
		if (a->numero > b->numero)
		{
			return a;
		}
		else
		{
			return b;
		}
	}
	void HeapifyDown(int i)
	{
		if (LChild(i)<taken-1)
		{
			T mayor;
			if (RChild(i) < taken-1)
			{
				mayor = Mayor(heap->at(LChild(i)), heap->at(RChild(i)));
			}
			else mayor = heap->at(LChild(i));
			if (heap->at(LChild(i)) == mayor && heap->at(LChild(i))->numero > heap->at(i)->numero)
			{
				swap(heap->at(LChild(i)),heap->at(i));
				i=LChild(i);
				HeapifyDown(i);
			}
			else if (RChild(i) < taken - 1)
			{
				if (heap->at(RChild(i)) == mayor && heap->at(RChild(i))->numero > heap->at(i)->numero)
				{
					swap(heap->at(RChild(i)), heap->at(i));
					i = RChild(i);
					HeapifyDown(i);
				}
			}
		}
	}
	T Extract()
	{
		if (heap != NULL)
		{
			T aux = heap->at(0);
			heap->at(0) = heap->at(taken-1);
			heap->pop_back();
			HeapifyDown(0);
			taken--;
			cout << endl;
			return aux;
		}
	}
	
};

int main()
{
	CBinaryHeap<CAlumno*>*heap = new CBinaryHeap<CAlumno*>();
	heap->Insert(new CAlumno("Julio", "20181b262", 0));
	heap->Insert(new CAlumno("Julio", "20181b262", 1));
	heap->Insert(new CAlumno("Julio", "20181b262", 2));
	heap->Insert(new CAlumno("Julio", "20181b262", 3));
	heap->Insert(new CAlumno("Julio", "20181b262", 4));
	heap->Insert(new CAlumno("Julio", "20181b262", 12));
	heap->Insert(new CAlumno("Julio", "20181b262", 18));
	heap->Insert(new CAlumno("Julio", "20181b262", 9));
	heap->Insert(new CAlumno("Julio", "20181b262", 10));
	heap->Extract()->Print();
	heap->Insert(new CAlumno("Julio", "20181b262", 33));
	heap->Insert(new CAlumno("Julio", "20181b262", 49));
	heap->Insert(new CAlumno("Julio", "20181b262", 8));
	heap->Insert(new CAlumno("Julio", "20181b262", 30));
	heap->hPrint();
	cout << endl;
	heap->Extract()->Print();
	heap->Extract()->Print();
	heap->Extract()->Print();
	heap->Extract()->Print();
	heap->Extract()->Print();
	heap->Extract()->Print();
	heap->Extract()->Print();
	heap->Printerino();
	cout << endl;
	heap->Load();
	heap->hPrint();
	heap->Printerino();
	_getch();
	return 0;
}