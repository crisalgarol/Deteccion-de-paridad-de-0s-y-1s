//Cabecera

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <winbgim.h>
#include <time.h>
#include <math.h>

#define q0 0
#define q1 1
#define q2 2
#define q3 3

unsigned int calcular_tamano(char name [30]);
int evaluar(char l, int state);
void historial(char l, int state, FILE *archivo);
void dibujar();
int leer_desde_archivo(char name [30], int tam);
int procesar_string(char nombre[30], int tam);
void crear_binario(char* cad ,int tam);

