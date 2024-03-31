#include <iostream>
#include <matrixGen.h>
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
