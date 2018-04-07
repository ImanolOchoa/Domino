#pragma once
#include "Ficha.h"

// Clase lista que sera la que contenga las listas no contiguas con las fichas

class Lista {

	ficha *primeraFicha; 	// Puntero que apuntara a la primera ficha de la cola

	bool exito; // Variable que mientras que sea falsa el juego no se detendrá solo sera true si algun jugador se queda sin fichas


public:

	// Constructor de las listas
	// Se encargará de poner el puntero primeraFicha apuntado a NULL
	// la variable exito a false

	Lista();

	// Funcion que tratara de generar cada una de las fichas
	// consta de dos bucles for que generan las 28 fichas del domino
	// la primnera ficha siempre sera el doble blanco o doble 0

	void generarFichas();

	// Funcion que recibe una ficha y que la insertara en la mano del jugador

	bool inertarFichas(ficha *ficha, int pos);

	// Funcion que recorre las listas
	// devuelve el tamaño de la lista

	int getTamanio();

	// Funcion que te lleva a una posicion determinada de la lista
	// Necesita que se le pase la posicion

	ficha *goTo(int pos);

	//destructor

	~Lista();

};