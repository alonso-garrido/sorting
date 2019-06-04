#include <conio.h>
#include <iostream>
#include <string>
#include "HashMap.h"
#include "CAlumno.h"
using namespace std;

int main()
{
	bool exit = true;
	HashMap<CAlumno*>*map = new HashMap<CAlumno*>();
	while (exit)
	{
		string str, cod, car;
		int cic;
		cout << "Ingrese el nombre a ingresar: " << endl;
		getline(cin, str);
		if (str == "salir")break;
		cout << "Ingrese el codigo del alumno: " << endl;
		getline(cin, cod);
		cout << "Ingrese la carrera del alumno: " << endl;
		getline(cin, car);
		cout << "Ingrese el ciclo del alumno: " << endl;
		cin >> cic;
		cin.ignore();
		CAlumno*aux = new CAlumno(str, cod, car, cic);
		map->insert(aux->getnombre(), aux);
	}

	cout << "Ingrese el nombre a buscar: " << endl;
	string get; 
	getline(cin, get);
	map->get(get)->Print();
	_getch();
	return 0;
}