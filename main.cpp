#include "paridad.h"

int main(){
	
	int tam, i, state = q0, cont=0;
	FILE *temp = fopen("temp.txt", "w+");
	char name[30], opc, *leido, c;
	
	srand(time(0));
	
	if(temp == NULL){
		printf("Error en el archivo\n\n");
		return -1;
	}
	
	
	
	printf("Como desea trabajar?\n\n1)Evaluar un numero\n2)Leer un numero desde archivo\n3)Crear un numero aleatorio\n4)Ver grafo\n\n-->");
	scanf("%c", &opc);
	
	system("cls");

	switch(opc){
	
		case '1':
			
			printf("Ingrese el numero:");
			fflush(stdin);
			while( (c = getchar()) != '\n')    {		
					fputc(c, temp);
					cont++;
			}	
			fflush(stdin);
			fclose(temp);
			tam = calcular_tamano("temp.txt");	
			printf("El valor de tam: %d", tam);
			fopen("temp.txt", "r");
			leido = (char*) malloc( sizeof(char) * tam);
	
			if(leido == NULL){
					printf("\nError al asignar memoria!");
					return(-1);}
					
			fgets(leido,tam,temp);
			puts(leido);
			tam--;
			leido[tam] = '\0';
			fclose(temp);
			procesar_string(leido, tam);
			free(leido);
			fclose(temp);
			break;
		
		case '2':
			printf("Ingrese el nombre del archivo (Recuerde escribir la extension): ");
			fflush(stdin);
			gets(name);
			tam = strlen(name);
			name[tam] = '\0';
			tam = calcular_tamano(name);
			leer_desde_archivo(name, tam);
			break;
		
		case '3':
			printf("Ingresa el tamano de digitos: ");
			fflush(stdin);
			scanf("%d", &tam);
			
			leido = (char*) malloc( sizeof(char) * tam );
			
			if(leido == NULL){
				printf("Error al asignar memoria\n");
				exit(-1);
			}
			
			fflush(stdin);
			printf("El numero generado fue: ");
			crear_binario(leido, tam);
			fflush(stdin);
			procesar_string(leido, tam);
			puts(leido);
			break;
		
		case '4':
			dibujar();	
			break;
		
		default:
			printf("\nOpcion no valida, intente de nuevo!!");
			break;
	}
	
	
	
	
	return 0;
}

