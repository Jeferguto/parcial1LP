#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para intercambiar dos elementos
void cambiarPosicion(int *x, int *y) {
    int temp = *x; // Guardar el valor de x en una variable temporal
    *x = *y; // Asignar el valor de y a x
    *y = temp; // Asignar el valor de la variable temporal a y
}

// Función para particionar el array
int dividirArray(int arreglo[], int bajo, int alto) {
    int pivote = arreglo[alto]; // Seleccionar el pivote (último elemento)
    int indiceMenor = bajo - 1; // Índice del elemento menor

    // Recorrer el array desde bajo hasta alto - 1
    for (int j = bajo; j < alto; j++) {
        if (arreglo[j] < pivote) { // Si el elemento actual es menor que el pivote
            indiceMenor++;
            cambiarPosicion(&arreglo[indiceMenor], &arreglo[j]); // Intercambiar los elementos
        }
    }
    cambiarPosicion(&arreglo[indiceMenor + 1], &arreglo[alto]); // Colocar el pivote en su posición correcta
    return indiceMenor + 1; // Devolver el índice del pivote
}

// Función de ordenación rápida (Quicksort)
void ordenarRapido(int arreglo[], int bajo, int alto) {
    if (bajo < alto) { // Condición de recursión
        int indicePivote = dividirArray(arreglo, bajo, alto); // Dividir el array y obtener el índice del pivote
        ordenarRapido(arreglo, bajo, indicePivote - 1); // Ordenar la parte izquierda
        ordenarRapido(arreglo, indicePivote + 1, alto); // Ordenar la parte derecha
    }
}

// Función para imprimir el array
void mostrarArray(int arreglo[], int tamaño) {
    for (int i = 0; i < tamaño; i++) // Recorrer el array
        printf("%d ", arreglo[i]); // Imprimir cada elemento
    printf("\n"); // Salto de línea al final
}

int main() {
    int longitud = 10000; // Tamaño del array
    int *miArray = (int *)malloc(longitud * sizeof(int)); // Reservar memoria dinámica para el array

    if (miArray == NULL) { // Verificar si la asignación de memoria falló
        printf("Error de memoria\n");
        return 1; // Salir del programa con error
    }

    srand(time(0)); // Inicializar la semilla del generador de números aleatorios

    for (int i = 0; i < longitud; i++) { // Llenar el array con valores aleatorios
        miArray[i] = rand() % 10000;
    }

    clock_t inicio = clock(); // Medir el tiempo de inicio antes de ordenar
    ordenarRapido(miArray, 0, longitud - 1); // Ordenar el array usando quicksort
    clock_t fin = clock(); // Medir el tiempo de fin después de ordenar

    double tiempoTotal = ((double)(fin - inicio)) / CLOCKS_PER_SEC; // Calcular el tiempo de ejecución
    printf("Tiempo de ordenación: %f segundos\n", tiempoTotal); // Mostrar el tiempo de ejecución

    free(miArray); // Liberar la memoria asignada
    return 0; // Fin del programa
}

