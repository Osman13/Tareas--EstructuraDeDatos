// SemaforoNodo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <array>

using namespace std;

class Nodo
{
public:
	string name;
	list<Nodo*>adj;
	int grupo = 0;
};

	int grupoActual = 1;
	bool esActual = true;
	Nodo grafos[];

	Nodo buscar(Nodo grafo[])
	{
		for (int i = 0; i < sizeof(grafo); i++)
			if (grafo[i].grupo == 0)
				return grafo[i];
			else
				return NULL;
	}

	void asignar(Nodo actual)
	{
		actual.grupo = grupoActual;
	}

	void buscarPermitidos(Nodo grafo[])
	{
		for (int i = 0; i < sizeof(grafo); i++) {
			if (grafo[i].grupo == 0) {
				for (Nodo* actual : grafo[i].adj) {
					if (actual->grupo == grupoActual) {
						esActual = false;
					}
					if (esActual)
						asignar(grafo[i]);
				}
			}
		}
	}

int main()
{
	for (int i = 0; i < sizeof(&grafos); i++)
	{
		if (&grafos[i] != NULL)
		{
			Nodo actual = grafos[i];
			asignar(actual);
			buscarPermitidos(&grafos[i]);
			grupoActual++;
		}
	}
    return 0;
}