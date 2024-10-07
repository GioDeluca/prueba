#include <iostream>
#include "listas_rec.hpp" //_rec x recortada, es la de fragmentos sin insertar_unico

using namespace std;

struct Deuda {
	string cliente;
	int mes;
	int cant;
};

//por cliente y ante igualdad por mes, ambos ascendente
int critdeu(Deuda a, Deuda b)
{
	if (a.cliente == b.cliente)
		return a.mes - b.mes;
	else
		return a.cliente > b.cliente ? 1 : -1;
}

ostream& operator << (ostream &os, const Deuda& deuda)
{
	os << deuda.cliente << " - mes: " << deuda.mes
	   << " - cant: " << deuda.cant;
	return os;
}

template <typename T> void mostrar(T vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << vec[i] << endl;
}

template <typename T> Nodo<T>* insertar_unico(T valor, Nodo<T>*& lista, int (*criterio)(T, T))
{
	if (lista == nullptr || criterio(valor, lista->dato) < 0) {
		Nodo<T>* nuevo = new Nodo<T>; //Genero nodo
		nuevo->dato = valor; // y guardo el valor
		nuevo->sig = lista;
		lista = nuevo;
		return nuevo;
	} else {
		if (criterio(valor, lista->dato) == 0) //Si justo es igual al primero
			return lista;
		Nodo<T>* p = lista;
		while (p->sig != nullptr && criterio(valor, p->sig->dato) > 0)
			p = p->sig;
		if (p->sig != nullptr && criterio(valor, p->sig->dato) == 0) {
			return p->sig; //devuelvo el que ya estaba en la lista
		} else {
			Nodo<T>* nuevo = new Nodo<T>; //Genero nodo
			nuevo->dato = valor; // y guardo el valor
			nuevo->sig = p->sig;
			p->sig = nuevo;
			return nuevo;
		}
	}
}

int main()
{
	const int dim = 17;
	Deuda vdeu[dim] = {
		{"Pedro", 12, 164}, {"Pedro", 6, 37}, {"Maria", 7, 474},
		{"Pedro", 12, 255}, {"Pedro", 12, 155}, {"Juan", 3, 377},
		{"Maria", 9, 260}, {"Ana", 2, 52}, {"Maria", 7, 95},
		{"Maria", 5, 243}, {"Juan", 3, 218}, {"Juan", 5, 75},
		{"Juan", 3, 284}, {"Pedro", 6, 69}, {"Juan", 6, 184},
		{"Ana", 6, 446}, {"Ana", 2, 272}
	};
	Nodo<Deuda> *listaord = nullptr; //lista ordenada con repeticiones
	Nodo<Deuda> *listauni = nullptr; //lista ordenada sin repetir claves
	Nodo<Deuda> *listacons = nullptr;//lista ordenada y consolidada
	//es decir, acumulando deudas del mismo mes
	int i;
	cout << "=========== Vector Original ===========" << endl;
	mostrar(vdeu, dim);

	//Armamos una lista ordenada con repeticiones
	for (i = 0; i < dim; ++i)
		insertar(vdeu[i], listaord, critdeu); //insertar tradicional
	cout << endl << "=========== Ordenada con repeticiones ===========" << endl;
	mostrar(listaord);

	//Armamos una lista ordenada con elementos únicos
	for (i = 0; i < dim; ++i)
		insertar_unico(vdeu[i], listauni, critdeu); //insertar único
	cout << endl << "=========== Ordenada SIN repeticiones ===========" << endl;
	mostrar(listauni);

	//Armamos una lista consolidada similar a ejercicio guia anterior
	Deuda d0;
	d0.cant = 0;
	Nodo<Deuda> *pnodo;
	for (i = 0; i < dim; ++i) {
		d0.cliente = vdeu[i].cliente;
		d0.mes = vdeu[i].mes;
		pnodo = insertar_unico(d0, listacons, critdeu);
		pnodo->dato.cant += vdeu[i].cant;
	}
	cout << endl << "=========== Lista consolidada ===========" << endl;
	mostrar(listacons);

	return 0;
}
