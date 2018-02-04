#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
/*Como la math de Java. Importantes sqrt y pow*/
#include <string.h> 
/*para calcular la longitud del string con strlen y concatenar con strcat*/
#define COCHES 2
#define GASOLINA 1.09

int indice = 0;

typedef struct {
    char matricula[8];
    int num_km;
} coche;

coche COCHE[COCHES];
void anhade_coche();
float precio_clases(float combustible);
void *muestra_coches(coche* arg);
void inserta_km(int kms, int num_coche);
int km_totales(coche* arg);

int main ()	
{
    int seleccion;
    do
    {
       printf("Menú de la autoescuela. Estas son las opciones: \n \n ( 1). Muestra los datos de todos los coches. \n ( 2). Añade un nuevo coche a la autoescuela. \n ( 3). Calcula el precio de las clases. \n ( 4). Suma los kilómetros de todos los coches. \n ( 5). Añade más kilómetros recorridos a un coche.  \n (-1). Cerrar el programa. \n \n Seleccione la opción que desee de las anteriores introduciendo el valor entre paréntesis: \n");
    
        scanf("%i",&seleccion);
        switch (seleccion)
	    {
	    	case 1:
                printf("Ha seleccionado mostrar los datos de todos los coches. \n");
                muestra_coches(COCHE);
	    	    break;
            case 2:
                printf("Ha seleccionado añadir un nuevo coche a la autoescuela. \n");
                anhade_coche();
                break;
            case 3:
                printf("Ha seleccionado calcular el precio de las clases. \n Introduzca el valor actual del combustible: \n");
                float combustible;
                scanf("%f",&combustible);
                float clases = precio_clases(combustible);
                printf("Este es el precio de las clases: %.2f \n", clases);
                break;
            case 4:
                printf("Ha seleccionado sumar los kilómetros de todos los coches.");
                int b = km_totales(COCHE);
                printf("La suma es: %i \n", b);
                break;
            case 5:
                printf("Ha seleccionado añadir más kilómetros a un coche. \n A qué coche desea hacerlo? Introduzca un número del 0 al %i \n", COCHES);
                int coche_escogido;
                scanf("%i",&coche_escogido);
                printf("Qué cantidad desea añadir? \n");
                int km_a_anhadir;
                scanf("%i",&km_a_anhadir);
                inserta_km(km_a_anhadir, coche_escogido);
                break;
	    	default:
	    	   break;
	    } 
    } 
    while(seleccion > 0);

    return(0);
}

void *muestra_coches(coche* arg)
{
    int i;
    for(i = 0; i < COCHES; i++) 
    {
        printf("Matrícula: %s Kilómetros: %i \n", (arg[i].matricula), (arg[i].num_km));
    } 
}

void anhade_coche()
{
    printf("Escribe la matrícula (7 caracteres) \n");
    char matricula[8];
    scanf("%s",matricula); 
    getchar();
    float kilometros;
    do
    {
        printf("Introduzca los kilómetros: \n");
        if(scanf("%f",&kilometros) != 1)
        {
            printf("Esto no es una cantidad válida \n");
            kilometros = -1.0;
        }
         getchar();  
    }
    while(kilometros < 0);
    coche *p;
    p = &COCHE[indice];
    strcpy(p->matricula,matricula);
    p -> num_km = kilometros;
    indice++;
}

float precio_clases(float combustible)
{
    float a = pow(combustible, 3);
    a = a*4;
    return(a);
}

int km_totales(coche* arg)
{
    int i;
    float km_recorridos;
    for(i = 0; i < COCHES; i++)
    {
        km_recorridos = km_recorridos + arg[i].num_km;
    }
    return(km_recorridos);
}

void inserta_km(int kms, int num_coche)
{
    coche *c;
    c = &COCHE[num_coche];
    kms = COCHE[num_coche].num_km +kms;
    c -> num_km = kms;
}