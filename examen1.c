#include <stdio.h>  
#include <stdlib.h>
#include <math.h>
/*Como la math de Java. Importantes sqrt y pow*/
#include <string.h> 
/*para calcular la longitud del string con strlen y concatenar con strcat*/
#define LIBROS 5
#define IVA 1.21

int indice = 0;

typedef struct {
    char titulo[20];
    float precio;
    char ISBN[20];
    int numero_propio;
} libro;

libro LIBRO[LIBROS];
void *muestra_titulo(libro* arg);
void *muestra_libros(libro* arg);
int raiz_cuadrada(libro arg);
void imprimeCadena(char* cadena);
void anhade_libro();
float suma_todos(libro* arg);

int main ()	
{
    int seleccion;
    do
    {
       printf("Menú de la librería. Estas son las opciones: \n \n ( 1). Muestra el título de todos los libros. \n ( 2). Muestra un listado de todos los libros con sus datos. \n ( 3). Añade un nuevo libro a la librería. \n ( 4). Suma todos los precios de los libros y les añade el IVA. \n ( 5). Hace la raíz cuadrada del número propio de un libro para sacar su sección.  \n (-1). Cerrar el programa. \n \n Seleccione la opción que desee de las anteriores introduciendo el valor entre paréntesis: \n");
    
        scanf("%i",&seleccion);
        switch (seleccion)
	    {
	    	case 1:
                printf("Ha seleccionado mostrar el título de los libros. \n");
                muestra_titulo(LIBRO);
	    	    break;
            case 2:
                printf("Ha seleccionado mostrar un listado de todos los libros. \n");
                muestra_libros(LIBRO);
                break;
            case 3:
                printf("Ha seleccionado añadir un nuevo libro a la librería. \n");
                anhade_libro();
                break;
            case 4:
                printf("Ha seleccionado sumar los precios de todos los libros y aplicarles el IVA.");
                float b = suma_todos(LIBRO);
                printf("La suma con el IVA es: %.2f \n", b);
                break;
            case 5:
                printf("Ha seleccionado hacer la raíz cuadrada del número propio de un libro para sacar su sección. \n De qué libro desea hacerlo? Introduzca un número del 0 al 4 para escoger el libro: \n");
                int libro_escogido;
                scanf("%i",&libro_escogido);
                int a = raiz_cuadrada(LIBRO[libro_escogido]);
                printf("Esta es la sección(raíz cuadrada entera del número propio): %i \n", a);
                break;
            case -1:
                return(0);
	    	default:
	    	   break;
	    } 
    } 
    while(seleccion != -1);
    
    /*Main para las pruebas:
    
    strcpy(LIBRO[0].titulo,"Título 1");
    LIBRO[0].precio = 10;
    strcpy(LIBRO[0].ISBN, "334433");
    LIBRO[0].numero_propio = 23;
    strcpy(LIBRO[1].titulo,"Título 2");
    strcpy(LIBRO[2].titulo,"Título 3");
    strcpy(LIBRO[3].titulo,"Título 4");
    anhade_libro();
    muestra_titulo(LIBRO);
    muestra_libros(LIBRO);
    int a = raiz_cuadrada(LIBRO[0]);
    printf("%i \n", a);
    imprimeCadena("ABCDEF");
    float b = suma_todos(LIBRO);
    printf("%.2f \n", b);
    return(0);
    
    */
}

void *muestra_titulo(libro* arg)   /* cabecera de función */
{
    int i;
    for(i = 0; i < LIBROS; i++) 
    {
        printf("Título: %s \n", (arg[i].titulo));
    }
}

void *muestra_libros(libro* arg)
{
    int i;
    for(i = 0; i < LIBROS; i++) 
    {
        printf("Título: %s Precio: %.2f ISBN: %s Número propio: %i \n", (arg[i].titulo), (arg[i].precio), (arg[i].ISBN), (arg[i].numero_propio));
    } 
}

void anhade_libro()
{
    printf("Escribe 20 caracteres \n");
    char titulo[20];
    scanf("%s",titulo); 
    getchar();
    float precio;
    do
    {
        printf("Introduzca el precio: \n");
        if(scanf("%f",&precio) != 1)
        {
            printf("Esto no es un precio válido \n");
            precio = -1;
        }
         getchar();  
    }
    while(precio < 0);
    char isbn[20];
    printf("Escribe 20 caracteres \n");
    scanf("%s",isbn); 
    getchar();
    int numero_propio;
    do
    {
        printf("Introduzca el número propio: \n");
        if(scanf("%i",&numero_propio) != 1)
        {
            printf("Esto no es un número propio válido \n");
            numero_propio = -1;
        }
         getchar();  
    }
    while(numero_propio < 0);
    libro *p;
    p = &LIBRO[indice];
    strcpy(p->titulo,titulo);
    strcpy(p->ISBN, isbn);
    p -> precio = precio;
    p -> numero_propio = numero_propio;
    indice++;
}

void imprimeCadena(char* cadena)
{
    int i;
    for(i = 0; i < strlen(cadena); i++) 
    {
        printf("%c \n", (cadena[i]));
    }
}

float suma_todos(libro* arg)
{
    int i;
    float precios;
    for(i = 0; i < LIBROS; i++)
    {
        precios = precios + arg[i].precio;
    }
    precios = precios*IVA;
    return(precios);
}

int raiz_cuadrada(libro arg)
{
    int a = sqrt((arg.numero_propio));
    return(a);
}