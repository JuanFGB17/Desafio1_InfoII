#include <iostream>
#include "matrixGen.h"
using namespace std;

// Función para generar una matriz con números consecutivos dejando el centro vacío
int** generarMatriz(int n) {
    // Verificar que el tamaño de la matriz sea impar
    if (n % 2 == 0) {
        cout << "El tamaño de la matriz debe ser impar." << endl;
        return nullptr;
    }

    // Crear e inicializar la matriz de tamaño n x n
    int **matriz = new int*[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[n];
    }

    // Rellenar la matriz con números consecutivos
    int numero = 1;
    int centro = n / 2;
    for (int fila = 0; fila < n; fila++) {
        for (int col = 0; col < n; col++) {
            if (fila == centro && col == centro) {
                matriz[fila][col] = 0;  // Dejar el centro vacío
            } else {
                matriz[fila][col] = numero++;
            }
        }
    }
    return matriz;
}

// Función para rotar la matriz en sentido antihorario
void rotarMatriz(int** matriz, int n) {
    // Iterar a través de las capas concéntricas de la matriz
    for (int capa = 0; capa < n / 2; ++capa) {
        int limite = n - capa - 1; // Límite para la iteración en cada capa

        // Iterar a través de los elementos de cada capa
        for (int i = capa; i < limite; ++i) {
            // Guardar el valor superior izquierdo
            int temp = matriz[capa][i];

            // Mover el valor inferior izquierdo al superior izquierdo
            matriz[capa][i] = matriz[i][n - 1 - capa];

            // Mover el valor inferior derecho al inferior izquierdo
            matriz[i][n - 1 - capa] = matriz[n - 1 - capa][n - 1 - i];

            // Mover el valor superior derecho al inferior derecho
            matriz[n - 1 - capa][n - 1 - i] = matriz[n - 1 - i][capa];

            // Mover el valor superior izquierdo al superior derecho
            matriz[n - 1 - i][capa] = temp;
        }
    }
}

// Función para imprimir la matriz
void imprimirMatriz(int** matriz, int n) {
    for (int fila = 0; fila < n; fila++) {
        for (int col = 0; col < n; col++) {
            cout << matriz[fila][col] << " ";
        }
        cout << endl;
    }
}

// Función para liberar la memoria de la matriz
void liberarMatriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

