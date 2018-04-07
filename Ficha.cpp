#include "Ficha.h"

ficha::ficha(int nA, int nB, ficha *fichaDespues) {

	this->nArriba = nA; // Igualo el numero de arriba al argumento que me pasan
	this->nAbajo = nB; // Igualo el numero de abajo al argumento que me pasan

	this->siguienteFicha = fichaDespues; // Apunto la ficha a la siguiente ficha o a NULL

}

ficha::~ficha() {



}
