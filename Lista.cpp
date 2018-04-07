#include "Lista.h"

Lista::Lista() {

	this->primeraFicha = NULL; // Apunta la primera ficha a NULL
	this->exito = false; // Exito sera false

}

void Lista::generarFichas() {

	ficha *fichas; // Puntero auxiliar

	for (int i = 0; i <= 6; i++) { // Valores que tomaran las caras de arriba(nArriba)
	
		for (int j = 0; j <= 6; j++) { // Valores que tomaran las caras de abajo(nAbajo)

			if ((i == 0) && (j == 0)) { // La primera ficha siempre sera la [0|0]

				this->primeraFicha = new ficha(i, j); // Igualo la primera ficha a los valores de i y j que toma la ficha auxiliar
				fichas = this->primeraFicha; // Actualizo la variable auxiliar

			}
			else {

				fichas->siguienteFicha = new ficha(i, j); // Igualo la primera ficha a los valores de i y j que toma la ficha auxiliar
				fichas = fichas->siguienteFicha; // Actualizo la variable auxiliar

			}

		}

	}

}

bool Lista::inertarFichas(ficha *fichaAInsertar , int pos) {

	bool sePuedeIsertar = false; // Supongo desde el principio que la ficha no se puede insertar

	if (pos <= this->getTamanio() + 1) { // Compruebo que no inserto en un tamaño mayor al de la lista

		if (pos == 1) { // Caso de primera posicion

			if (fichaAInsertar != NULL) { // La Primera ficha no a de estar vacía

				fichaAInsertar->siguienteFicha = primeraFicha; // Inserto la ficha detras de la primera ficha
				primeraFicha = fichaAInsertar; // apunto la primera ficha a la nueva ficha
				sePuedeIsertar = true;	// Actualizo el esta a que si se ha podido insertar la ficha

			}
			else {

				sePuedeIsertar = false; // Actualizo el esta a que no se ha podido insertar la ficha

			}

		}
		else if (pos == this->getTamanio() + 1) { // Caso de última posicion

			if (fichaAInsertar != NULL) {

				ficha *aux = this->primeraFicha; // uso de una variable auxiliar para no perder refencias

				if (aux != NULL) {

					while (aux->siguienteFicha != NULL) { // Me muevo hasta la ultima posicion que es cuando el ultimo puntero apunta a NULL

						aux = aux->siguienteFicha; // Actualizo la ficha auxiliar

					}

					aux->siguienteFicha = fichaAInsertar; // Una vez llego a la posicion final apunto la auxiliar a mi ficha
					fichaAInsertar->siguienteFicha = NULL; // Una vez isertada la ficha la apunto a NULL puesto que es la ultima de todas
					
					sePuedeIsertar = true; // Actualizo el esta a que si se ha podido insertar la ficha

				}

			}
			else {

				sePuedeIsertar = false; // Actualizo el esta a que no se ha podido insertar la ficha

			}

		}
		else { // Se inserta en una posicion que no ni la primera ni la última

			ficha *aux = this->goTo(pos - 1); // Igualo la variable auxiliar a la ficha anterior

			if (aux != NULL) { // Aux no puede estara vacia

				if (fichaAInsertar != NULL) { // La ficha a insertar tampoco puede estar vacía

					fichaAInsertar->siguienteFicha = aux->siguienteFicha; // Apunto la ficha a insertar a la ficha que sigue a la auxiliar
					aux->siguienteFicha = fichaAInsertar; // Apunto la auxiliar a la siguiente que ahora es la ficha a insertar

					sePuedeIsertar = true; // Actualizo el esta a que si se ha podido insertar la ficha

				}

				else {

					sePuedeIsertar = false; // Actualizo el esta a que no se ha podido insertar la ficha

				}

			}

		}

	}
	else {

		sePuedeIsertar = this->inertarFichas(fichaAInsertar, this->getTamanio() + 1); // En el caso de no haber sido insertada se vuelve a llamar pero con el parametro del tamaño mas uno

	}

	return sePuedeIsertar;

}

int Lista::getTamanio() {

		int tamanio = 0; // Valor del tamaño de mi lista

		if (this->primeraFicha != NULL) { // Solo existira una lista si la primera ficha no esta apuntando a NULL

			ficha *aux = this->primeraFicha; // Igualo la primera ficha a la variable auxiliar para no perder la referencia

			do {

				tamanio++; // Actualizo el tamaño de la lista

				aux = aux->siguienteFicha; // Actualizo la auxiliar a la siguiente ficha

			} while (aux != NULL); // Solo se ejecutara mientra que la ficha auxiliar no este en su valor por defecto que es NULL 
								   // Ya que a NULL estara apuntando la ultima ficha

		}

		return tamanio; // Devuelvo el tamaño de la cadena

}


ficha * Lista::goTo(int pos) {

	ficha *aux = primeraFicha; // Variable auxiliar para no perder la refencia de la primera ficha

	for (int i = 1; i<pos && aux != NULL; i++) { // Voy avanzando x posiciones hasta que la posicion se pide o hasta la final si la posicion es mayor al tamaño de la lista

		aux = aux->siguienteFicha; // Actualizo aux a la siguiente ficha

	}

	return aux;

}


Lista::~Lista() {



}