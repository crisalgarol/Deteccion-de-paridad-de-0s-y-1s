#include "paridad.h"



int leer_desde_archivo(char name[30], int tam){
	
		FILE *archivo = fopen (name, "r"); 
		int i, state = q0;
		char* leido;
	
		
		leido = (char*) malloc( sizeof(char) * tam);
	
							if(leido == NULL){
							printf("\nError al asignar memoria!");
							return(-1);
								}
							if( archivo == NULL){
							printf("\nError al abrir archivo!\n\n");
							return (-1);
							}
							
		fgets(leido, tam, archivo);
		puts(leido);
		tam--;
		leido[tam] = '\0';
		procesar_string(leido, tam);
		



			
	

	}							
							
int procesar_string (char* cadena, int tam){
	
	int i, state = q0;
	FILE *timeline = fopen("Historial.txt", "w+");

			for(i=0; i<tam; i++){
				
			state = evaluar(cadena[i], state);
			historial(cadena[i], state, timeline);
			printf("%c %d\n", cadena[i], state);
				
			if(state == -1){
				printf("Error!. Numero no valido. Solo se admiten 0's y 1's\n\n");
				return -1;	
			}
		}		
			tam--; //VERIFICAR 
		
			if(state == q0)
			printf("\nExiste paridad de ceros y unos\n\n");
			
			else		
			printf("\nNO existe paridad\n\n");
		
}
	
void crear_binario(char* cad, int tam){
	int i=0;
	
		for(i; i<tam; i++){
			cad[i] =(char) ((rand()%2) + 48);	
			printf("%c",cad[i]);
		}
		
}

	
int evaluar(char l, int state){
	
	if( l == '0'){
		
		switch(state){
			
			case q0:
				return q1;
			break;
				
			case q1:
				return q0;
			break;
			
			case q2:
				return q3;
			break;
			
			case q3:
				return q2;
			break;
			
			default:
			break; 
		}
	
	}
	
	else if( l == '1'){
		
		switch(state){
		
		case q0:
			return q2;
			break;
		
		case q1:
			return q0;
			break;
		
		case q2: 
			return q0;
			break;
		
		case q3:
			return q1;
			break;
			
		default:
		break;
			
		}
		
		
	}
	
	else
		return -1;
}

unsigned int calcular_tamano(char name[30]){
FILE* numbin = fopen(name, "r+b");
unsigned int tam;


if (numbin == NULL){
	system("cls");
	printf("Archivo no encontrado!");
	return -1;
}

//Calcular el tamaño de la cadena
fseek(numbin, 0L, SEEK_END);
tam = ftell(numbin)/sizeof(char);
fclose(numbin);
return tam;

}

void historial(char l, int state, FILE *archivo){
	fputc(l, archivo);
	fprintf(archivo, "%s", " = q");
	fprintf(archivo, "%d", state);
	fprintf(archivo, "%s", "\n");
}

