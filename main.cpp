#include <iostream>
#include <matrixGen.h>
#include <configKey.h>
using namespace std;


void imprimirMatriz(int** matriz, int n);
void liberarMatriz(int** matriz, int n);
void rotarMatrizAntihorario(int** matriz, int n);

int main()
{
    //Recibir información
    int compare, minSizeMat;
    cout << "La llave k esta conformada por (fila, columna, valores comparativos)" << endl;
    do{
        while (true){
            cout << "Cuantos valores comparativos desea ingresar" << endl;
            cin >> compare;
            if (cin.fail()){
                cin.clear();
                while (cin.get() != '\n') {
                    continue;}}
            else
                break;}
    }while(compare<=0);
    int *llave;
    llave=configuracionKey(compare, minSizeMat);

    //Procesar información
    cout << endl << "Minsizemat: " << minSizeMat <<endl;
    cout << "Compare: " << compare <<endl;
    for (int i = 0; i<=compare+1; i++){
        cout << llave[i] << ' ';}

    //Generar matriz


    int **matriz;
    matriz=generarMatriz(minSizeMat);

    liberarMatriz(matriz, minSizeMat);





    //Generar la cerradura



    delete [] llave;
    return 0;
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

// Función para rotar la matriz en sentido antihorario
void rotarMatrizAntihorario(int** matriz, int n) {
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
