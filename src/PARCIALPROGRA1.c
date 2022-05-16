

/*
 * 1. Crear una función llamada aplicarDescuento que reciba como parámetro
 *  el precio de un producto y devuelva
 * el valor del producto con un descuento del 5%.
 * Realizar la llamada desde el main.
 *
 *
 * 2. Crear una función que se llame contarCaracteres que reciba una cadena
 *   de caracteres como primer parámetro y un carácter como segundo
 *   y devuelva la cantidad de veces que ese carácter aparece en la cadena
 *
 *
 * 3. Dada la estructura Notebook(id, procesador, marca, precio)
 *   generar una función que permita ordenar un array de dicha estructura por marca.
 *   Ante igualdad de marca deberá
 *   ordenarse por precio. Hardcodear datos y mostrarlos desde el main.
 */
#include <stdio.h>
#include <stdlib.h>



typedef struct{

	int id;
	char procesador[20];
	char marca [20];
	float precio;

}eNotebook;




float aplicarDescuento(float precio);
int contarCaracteres(char cadena[], char a);
int ordenar(eNotebook notebooks[], int tam);
void mostrarNotebook(eNotebook notebook);

int main(void) {

	setbuf(stdout,NULL);

	char cadena[15] = "Valentina";


    printf("El precio con el descuento es :%.2f\n",aplicarDescuento(250));


	printf("%d\n", contarCaracteres(cadena, 'a'));



	return EXIT_SUCCESS;
}


float aplicarDescuento(float precio) {

	float descuento;
	float precioFinal;

	if (precio > 0) {

		descuento = (float) (5 * precio) / 100;

		precioFinal = precio + descuento;

	}

	return precioFinal;

}

int contarCaracteres(char cadena[], char a) {

	int contador = 0;
	int i = 0;

	if (cadena != NULL) {

		while (cadena[i] != '\0') {

			if (cadena[i] == a) {

				contador++;
			}
			i++;
		}

	}

	return contador;
}

int ordenar(eNotebook notebooks[], int tam) {

	int todoOk = 0;
	eNotebook aux;

	if (notebooks != NULL && tam > 0) {

		for (int i = 0; i < tam - 1; i++) {
			for (int j = i + 1; j < tam; j++) {

				if (notebooks[i].marca < notebooks[j].marca ||
					(notebooks[i].marca == notebooks[j].marca &&
					notebooks[i].precio > notebooks[j].precio)) {
					aux = notebooks[i];
					notebooks[i] = notebooks[j];
					notebooks[j] = aux;
				}

			}
		}

		todoOk = 1;
	}

	return todoOk;
}

void mostrarNotebook(eNotebook notebook){


	printf("  %d     %-10s%-10s     %5.2f        ",
			notebook.id,
			notebook.procesador,
			notebook.marca,
			notebook.precio

				);
}


