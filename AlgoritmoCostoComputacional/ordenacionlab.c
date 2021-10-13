
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Definiciones */
#define ALEATORIO 1
#define DECRECIENTE 2
#define CRECIENTE 3

#define TIPO_VECTOR(n) n == 1?"Aleatório":n == 2?"Decreciente":"Creciente"


/* Protótipos */
void ordena(void (*sort)(int *,int),int *V,int n,char *nombre,int tipoVector);
void generarVector(int *vec, int tipoVec, int n);
void printV(FILE *salida,int *V,int n); 
void swap(int *x,int *y);
void copy(int *V,int *C,int n);

void bubbleFlagSort(int *V,int n);
void insertionSort(int *V,int n);
void selectionSort(int *V,int n);
void shellSort(int *V,int n);
void merge(int *V,int ini,int medio,int final); /* para mergeSort */
void mergeSort(int *V,int n); /* Wrapper */
void mergeSortR(int *V,int ini,int final);
int  particion(int *V,int ini,int final); /* para quickSort */
void quickSort(int *V,int n); /* Wrapper */
void quickSortR(int *V,int ini,int final);


int main(int argc, char **argv) {
    int n = 0;
    int tipoVector = 0;
    int *vector;
    FILE *salida;
        
    /* Validación simple para la cantidad de argumentos */
    if (argc != 3)  {
        printf("Error de entrada.\n\tUsar: ordena cantidad(n > 0) tipo(1,2,3)\n\tEjemplo: ordena 1000 1\n");
        exit(1);
    }

    /* Obteniendo los valores de la línea de comando*/
    n = atoi(argv[1]);
    tipoVector = atoi(argv[2]);
    
    /* Limpia archivo para n < 100 */
    if (n < 100) {
        salida = fopen("salida.txt","w");
        if (salida == NULL) {
            printf("No es posible abrir el archivo.");
            exit(1);
        }
        fflush(salida);
        fclose(salida);
    }

    /* Asignar el vector para ordenar y copiar. */
    vector = (int *) malloc(n * sizeof(int));

    /* Generar los numeros del vector */ 
    generarVector(vector,tipoVector,n);
   

    /* Llama método bubbleFlag */
    ordena(bubbleFlagSort, vector, n,"Bolha com Flag",tipoVector);

    /* Llama  método insertion */
    ordena(insertionSort, vector, n,"Insercion",tipoVector);
    
    /* Llama método selection */
    ordena(selectionSort, vector, n, "Seleccion",tipoVector); 
    
    /* Llama método shell */
    ordena(shellSort, vector, n, "Shell",tipoVector); 
    
    /* Llama para o método merge */
    ordena(mergeSort, vector, n, "Merge",tipoVector); 
 
    /* Llama para o método quick */
    ordena(quickSort,vector,n,"Quick",tipoVector); 

    /* Liberando memória alocada*/
    free(vector);


    return 0;
}

/*
 * Llama a las funciones de clasificación y muestra los resultados en la salida estándar
 * si int n menor que 100 también escribe en el archivo output.txt
 * void (* sort) (int *, int) - Puntero a la función del método de ordenación
 * int * V - Vector a ordenar
 * int n - Tamaño del vector
 * char * name: cadena con el nombre del método que se mostrará en el archivo.
 * intvectortype - tipo de vector (aleatorio, decreciente, creciente)
 */
void ordena(void (*sort)(int *,int),int *V,int n,char *nombre,int tipoVector) {
    double tini,tfin,tiempo;
    int *cVetor = (int *) malloc(n * sizeof(int));

    copy(cVetor,V,n); /* Realiza una copia de seguridad de V para que pueda usarlo para varias llamadas */
    
    printf("%s (%d elementos - %s)\n", nombre, n, TIPO_VECTOR(tipoVector));
    if (n < 100) {
        FILE *salida;
        salida = fopen("salida.txt","a");
        if (salida == NULL) {
            printf("No se puede abrir el archivo.");
            exit(1);
        }
        fprintf(salida,"%s\nAntes: ",nombre);
        printV(salida,cVetor,n);
        tini = (double)clock() / CLOCKS_PER_SEC * 1000;
        sort(cVetor,n);
        tfin = (double)clock() / CLOCKS_PER_SEC * 1000;
        tiempo = (double) tfin - tini;
        fprintf(salida,"\nLuego: ");
        printV(salida,cVetor,n);
        fprintf(salida,"\n\n");
        fclose(salida);
    }
    
    else {
        tini = (double)clock() / CLOCKS_PER_SEC * 1000;
        sort(cVetor,n);
        tfin = (double)clock() / CLOCKS_PER_SEC * 1000;
        tiempo = (double) tfin - tini;
    }
    
    printf("Tiempo: %2.0lf ms\n\n", tiempo);
    
    free(cVetor);
}

/*
 * Imprime el vector V en la pantalla en el formato [1,2,3,4,5,6]
 * int *V - Vector de enteros
 * int n - Tamaño do vector
 */
void printV(FILE *salida,int *V,int n) {
    int i = 0;
    if (salida != NULL) 
       for (i = 0;i < n;i++)
           fprintf(salida,"%d ", V[i]);
}

/*
 * Copia  vector C para Vector V
 * int *V - Vector para donde  almacen
 * int *C - Vector que va ser copiado
 * int n - tamaño de vectores
 */
void copy(int *V,int *C,int n) {
    int i = 0;
    for (i = 0;i < n;i++)
        V[i] = C[i];
}


/*
 *Generador de contenido del vector según el tipo pasado en el parámetro tipoVec.
  * Rellena el vector vec y cVet con los mismos valores.
  * int * vec - Vector principal
  * int * cvec - Vector para copiar
  * int TipoVet - Tipo de llenado (ALEATORIO, ASCENDENTE, DISMINUYENTE)
  * int n - tamaño del vector
 */
void generarVector(int *vec, int tipoVec, int n) {
    int i = 0;

    switch (tipoVec) {
        case ALEATORIO:
            /* inicializando semilla */
            srand(time(NULL));
            for (i = 0;i < n;i++) 
                vec[i] = rand() % (n * 10);

            break;

        case CRECIENTE:
            for (i = 0;i < n;i++) 
                vec[i] = i;
            break;

        case DECRECIENTE:
            for (i = 0;i < n;i++)
                vec[i] = n - i - 1;
            break;

    }
}


void swap(int *x,int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;

}

/*********************************
 * Métodos de ordenacion
 *********************************/

void bubbleFlagSort(int *V,int n) {
    int flag;
    int j = 0;
    int i = 0;
    
    do {
        flag = 0;
        for (i = 0;i < n - 1 - j;i++) { 
	        if (V[i] > V[i+1]) {	
        	    swap(&V[i],&V[i+1]);
                flag = 1;
            }
        }
	    j++;	
    } while (flag);
}

void insertionSort(int *V,int n) {
    int i, j, pivo;
    
    for (i = 1;i < n;i++) {
        pivo = V[i];
        j = i - 1;
        while ((j >= 0) && (V[j] > pivo)) {
            V[j + 1] = V[j];
            j--;
        }
        V[j + 1] = pivo; 
    }
}


void selectionSort(int *V,int n) {
    int i, j, min;
    
    for (i = 0;i  < n-1;i++) {
        min = i;

        for (j = i + 1;j < n;j++)
            if (V[j] < V[min])  
                min = j;
	    
        swap(&V[i],&V[min]);
    }
}


void shellSort(int *V,int n) {
    int h = 1; 
    int i, j, pivo; /* Para insertion */
    
    do
        h = (3 * h) + 1;
    while (h < n);

    do { 
        h /= 3;
        /* insertion */
        for (i = h;i < n;i++) {
            pivo = V[i];
            j = i - h;
            while ((j >= 0) &&(pivo < V[j])) {
		        V[j + h] = V[j];
                j = j - h;
            }
            V[j + h] = pivo;
        }
        /* insertion */

    } while (h > 1);
}

/*************************
 * MergeSort
 *************************/
void merge(int *V,int ini,int medio,int final) {
    int i = ini;
    int j = medio + 1;
    int k = 0;
    int aux[final - ini + 1];
    
    while ((i <= medio) && (j <= final)) {
    	if (V[i] <= V[j]) {
            aux[k] = V[i];
            i++;
        }
        else {
            aux[k] = V[j];
            j++;
        }
        k++;
    }

    if (i <= medio)  {
        j = medio;
        while (j >= i) {
            V[final - medio + j] = V[j];
            j--;
        }
    }

    for (i = 0;i < k;i++) 
        V[ini + i] = aux[i];
    

}

void mergeSort(int *V,int n) {
    mergeSortR(V,0,n-1);
}

void mergeSortR(int *V,int ini,int final) {
    int medio;

    if (ini < final) {
        medio = (ini + final) / 2;
        if (ini < medio) 
            mergeSortR(V,ini,medio);
        if ((medio + 1) < final) 
            mergeSortR(V,medio + 1,final);
        
        merge(V,ini,medio,final);
    }
}

/*********************************
 * QuickSort
 ********************************/
int particion(int *V,int ini,int final) {
    int pivo = V[ini];
    int i = ini + 1;
    int j = final;
    
    while (i <= j) {
        while ((i <= j) && (V[i] <= pivo)) 
	        i++;
	    
        while (V[j] > pivo) 
            j--;
        
        if (i < j) {
            swap(&V[i],&V[j]);
            i++;
            j--;
        }
    }
    swap(&V[ini],&V[j]);
    return j;
}

void quickSort(int *V,int n) {
    quickSortR(V,0,n-1);
}

void quickSortR(int *V,int ini,int final) {
    int j;
    if (ini < final) {
        j = particion(V,ini,final);
        if (ini < (j - 1))
            quickSortR(V,ini,j - 1);
        if ((j + 1) < final) 
            quickSortR(V,j + 1,final);
    }
    
}
