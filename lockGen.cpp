#include <iostream>
#include <matrixGen.h>

using namespace std;

int *lockFinder(int **matriz, int *llave, int minSizeMat, int compare)
{
    int pin, sizeMat, fila, columna, cont=1;
    int *lockX = new int[compare+1];
    int **matriz1;

    if (llave[2]==1 && llave[0]==0 && llave[1]==minSizeMat-2){
        //rotar matriz inicial
        rotarMatriz(matriz, minSizeMat);
        imprimirMatriz(matriz, minSizeMat);
    }
    fila=llave[0];
    columna=llave[1];
    pin=matriz[fila][columna];
    sizeMat=minSizeMat;
    lockX[0] = sizeMat;
    for (int i = 2; i<compare+2; i++)
    {

        if (llave[i]==1){
            do{
                if(sizeMat>minSizeMat){
                    fila++;
                    columna++;
                }
                //funcion crea matriz
                matriz1=generarMatriz(sizeMat);
                imprimirMatriz(matriz1, sizeMat);
                cout<<endl;
                for (int j=0; j<3; j++) //veces que rotara la matriz para que se cumpla lo deseado = 3
                {
                    if (pin>matriz1[fila][columna]){
                        break;}
                    else{
                        //rotar matriz inicial
                        rotarMatriz(matriz1, sizeMat);
                        imprimirMatriz(matriz1, sizeMat);
                        cout<<endl;
                    }
                }
                if (pin<matriz1[fila][columna] || pin==matriz1[fila][columna]){
                    sizeMat += 2;
                    }
                    cout<<matriz1[fila][columna]<<endl;
            }while(pin<matriz1[fila][columna] || pin==matriz1[fila][columna]); //termina cuando se cumpla lo deseado
            pin=matriz1[fila][columna];

        }
        else if (llave[i]==0){
            do{
                if(sizeMat>minSizeMat){
                    fila++;
                    columna++;
                }
                //funcion crea matriz
                matriz1=generarMatriz(sizeMat);
                imprimirMatriz(matriz1, sizeMat);
                cout<<endl;
                for (int j=0; j<3; j++) //veces que rotara la matriz para que se cumpla lo deseado
                {
                    if (pin==matriz1[fila][columna]){
                        break;}
                    else{
                        //rotar matriz
                        rotarMatriz(matriz1, sizeMat);
                        imprimirMatriz(matriz1, sizeMat);
                        cout<<endl;
                    }
                }
                if (pin<matriz1[fila][columna] || pin>matriz1[fila][columna]){
                    sizeMat += 2;
                   }
                cout<<matriz1[fila][columna]<<endl;
            }while(pin!=matriz1[fila][columna]); //termina cuando se cumpla lo deseado
            pin=matriz1[fila][columna];
        }
        else {
            do{
                if(sizeMat>minSizeMat){
                    fila++;
                    columna++;
                }
                //funcion crea matriz
                matriz1=generarMatriz(sizeMat);
                imprimirMatriz(matriz1, sizeMat);
                cout<<endl;
                for (int j=0; j<3; j++) //veces que rotara la matriz para que se cumpla lo deseado
                {
                    if (pin<matriz1[fila][columna]){
                        break;}
                    else{
                        //rotar matriz inicial
                        rotarMatriz(matriz1, sizeMat);
                        imprimirMatriz(matriz1, sizeMat);
                        cout<<endl;
                    }
                }
                if (pin>matriz1[fila][columna] || pin==matriz1[fila][columna]){
                    sizeMat += 2;
                    }
                cout<<matriz1[fila][columna]<<endl;
            }while(pin>matriz1[fila][columna] || pin==matriz1[fila][columna]); //termina cuando se cumpla lo deseado
            pin=matriz1[fila][columna];
        }
        lockX[cont++] = sizeMat;
        cout << sizeMat <<" Tamano Matriz"<< endl;
        cout << pin <<" Este es el pin"<< endl;
        cout << fila <<" Este es la fila"<< endl;
        cout << columna <<" Este es la columna"<< endl;
        cout<<endl;
        sizeMat=minSizeMat;
        fila=llave[0];
        columna=llave[1];
    }
    liberarMatriz(matriz1, sizeMat);
    return lockX;
}
