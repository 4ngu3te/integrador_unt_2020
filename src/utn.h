/*
 * utn.h
 *
 *  Created on: 10 abr. 2020
 *      Author: FrancoGollo
 */

#ifndef UTN_H_
#define UTN_H_

int esPar(int/*parametro formal*/);
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int sumar(int* resultado, int x, int y);
int restar(int* resultado, int x, int y);
int dividir(int* resultado, int x, int y);
int multiplicar(int* resultado, int x, int y);
long int factorizarA(int* resultadoA, int x);
long int factorizarB(int* resultadoB, int y);
void MostrarArray(int pArray[],int cantidad);
void InicializarArray(int pArray[],int cantidad);
int SacarLaSuma(int pArray[], int cantidad);
void testArray(int pArray[],int cantidad);
int SacarCantidadCargada(int pArray[], int cantidad);

void get_string(char* mensaje,char* string);

int menuInformes();

int menuOrdenamiento();

void debug();

void text(char* text);

int esNumero(char* string);
int numero_valido(char* mensaje,char* mensaje_error,int min, int max,int intentos);
void modificarMayus(char *s,int todo);

int getString(char *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos,int mayus);

#endif /* UTN_H_ */
