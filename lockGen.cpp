#include <iostream>

using namespace std;

int *lockFinder(int **matriz1, int *llave, int minSizeMat, int compare)
{
    int pin, sizeMat, fila, columna, cont=0;
    int *lockX = new int[compare+1];

    if (llave[2]==1 && llave[0]==0 && llave[1]==minSizeMat-2){
        //funsion crea matriz inicial
        //rotar matriz inicial
    }
    else{
        //creacion matriz inicial
    }
    fila=llave[0];
    columna=llave[1];
    pin=matriz1[fila][columna];
    sizeMat=minSizeMat;
    for (int i = 2; i<compare+2; i++)
    {
        if (llave[i]==1){
            do{
                //funcion crea matriz
                for (int j=0; j<3; j++) //veces que rotara la matriz para que se cumpla lo deseado = 3
                {
                    if (pin>matriz1[fila][columna]){
                        pin=matriz1[fila][columna];
                        break;}
                    else{
                        //rotar matriz inicial
                    }
                }
                if (pin<matriz1[fila][columna] || pin==matriz1[fila][columna]){
                    sizeMat += 2;
                    fila++;
                    columna++;}
            }while(pin>matriz1[fila][columna]); //termina cuando se cumpla lo deseado
        }
        else if (llave[i]==0){
            do{
                //funcion crea matriz
                for (int j=0; j<3; j++) //veces que rotara la matriz para que se cumpla lo deseado
                {
                    if (pin==matriz1[fila][columna]){
                        pin=matriz1[fila][columna];
                        break;}
                    else{
                        //rotar matriz
                    }
                }
                if (pin<matriz1[fila][columna] || pin==matriz1[fila][columna]){
                    sizeMat += 2;
                    fila++;
                    columna++;}
            }while(pin==matriz1[fila][columna]); //termina cuando se cumpla lo deseado
        }
        else {
            do{
                //funcion crea matriz
                for (int j=0; j<3; j++) //veces que rotara la matriz para que se cumpla lo deseado
                {
                    if (pin<matriz1[fila][columna]){
                        pin=matriz1[fila][columna];
                        break;}
                    else{
                        //rotar matriz inicial
                    }
                }
                if (pin<matriz1[fila][columna] || pin==matriz1[fila][columna]){
                    sizeMat += 2;
                    fila++;
                    columna++;}
            }while(pin<matriz1[fila][columna]); //termina cuando se cumpla lo deseado
            cout << sizeMat << endl;
        }
        lockX[cont++] = sizeMat;
        cout << sizeMat << endl;
        sizeMat=minSizeMat;
        fila=llave[0];
        columna=llave[1];
    }
    return lockX;
}
