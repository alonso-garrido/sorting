#pragma once
#include <string>
#include <iostream>
using namespace std;
class CAlumno
{
private:
	string nombre;
	string codigo;
	string carrera;
	int ciclo;

public:
	CAlumno(string pnombre, string pcodigo, string pcarrera, int pciclo)
	{
		nombre = pnombre;
		codigo = pcodigo;
		carrera = pcarrera;
		ciclo = pciclo;
	};
	~CAlumno()
	{
		nombre = "";
		codigo = "";
		carrera = "";
		ciclo = NULL;
	};
	string getnombre()
	{
		return nombre;
	}
	string getcodigo()
	{
		return codigo;
	}
	string getcarrera()
	{
		return carrera;
	}
	int getciclo()
	{
		return ciclo;
	}
	void Print()
	{
		cout << "Nombre: " << nombre << endl << "Codigo: " << codigo << endl << "Carrera: " << carrera << endl << "Ciclo: " << ciclo << endl;
	}
};

