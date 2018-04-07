#pragma once
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

class ficha {

	int nArriba; // Variable de tipo entero que contiene uno de los dos números de una ficha de domino
	int nAbajo; // Variable de tipo entero que contiene el otro número de la ficha de domino

public:

	ficha *siguienteFicha; // puntero que apunta la siguiente ficha

	// Constructor de las Fichas
	// Se encargará de poner el punteros siguienteFicha apuntado a NULL por defecto o si se le pasa una ficha a esa ficha
	// las variable nAbajo y nArriba a -1 como valores por defecto o si se le pasa un valor al valor pasado

	ficha(int nA = -1, int nB = -1, ficha *fichaDespues = NULL);

	// No hace nada por el momento

	~ficha();
};