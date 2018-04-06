#include "Lista.h"

Lista::Lista() {

	this->primeraFicha = NULL;

}

void Lista::generarFichas() {

	for (int i = 0; i <= 6; i++) {
	
		for (int j = 0; j <= 6; j++) {

			if ((i == 0) && (j == 0)) {

				this->primeraFicha->nArriba = i;
				this->primeraFicha->nAbajo = j;

			}
			else {

				this->siguienteFicha->nArriba = i;
				this->siguienteFicha->nAbajo = j;

			}

		}

	}

}


Lista::~Lista() {



}
