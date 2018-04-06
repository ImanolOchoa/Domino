#pragma once
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

class ficha {

	int nArriba; // Variable de tipo entero que contiene uno de los dos números de una ficha de domino
	int nAbajo; // Variable de tipo entero que contiene el otro número de la ficha de domino

	ficha *siguienteFicha; // puntero que apunta la siguiente ficha

public:

	ficha(int nA, int nB);

};