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
    cout<<pin<<endl;
    sizeMat=minSizeMat;
    lockX[0] = sizeMat;
    for (int i = 2; i<compare+2; i++)
    {
        if (llave[i]==1){
            do{
                if (sizeMat<minSizeMat-2){
                    cout << "La llave ingresada no tiene posible cerradura." << endl;
                    break;
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
                if ((pin<matriz1[fila][columna] || pin==matriz1[fila][columna]) && fila>=1 && fila<=sizeMat-1 && columna>=1 && columna<=sizeMat-1){
                    sizeMat -= 2;
                    fila--;
                    columna--;
                }
                else if (pin<matriz1[fila][columna] || pin==matriz1[fila][columna]){
                    sizeMat += 2;
                    fila++;
                    columna++;
                }
                if (fila>=sizeMat || columna >= sizeMat){
                    cout << "La llave ingresada no tiene posible cerradura." << endl;
                    break;
                }
                    cout<<matriz1[fila][columna]<<endl;
            }while(pin<matriz1[fila][columna] || pin==matriz1[fila][columna]); //termina cuando se cumpla lo deseado
            pin=matriz1[fila][columna];

        }
        else if (llave[i]==0){
            do{
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
                cout<<matriz1[fila][columna]<<endl;
            }while(pin!=matriz1[fila][columna]); //termina cuando se cumpla lo deseado
            pin=matriz1[fila][columna];
        }
        else {
            do{
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
                    fila++;
                    columna++;
                    }
                cout<<matriz1[fila][columna]<<endl;
            }while(pin>matriz1[fila][columna] || pin==matriz1[fila][columna]); //termina cuando se cumpla lo deseado
            pin=matriz1[fila][columna];
        }
        cout << sizeMat <<" Tamano Matriz"<< endl;
        cout << pin <<" Este es el pin"<< endl;
        cout << fila <<" Este es la fila"<< endl;
        cout << columna <<" Este es la columna"<< endl;
        cout<<endl;
        if (fila>=sizeMat || columna >= sizeMat){
            break;
        }
        lockX[cont++] = sizeMat;
        liberarMatriz(matriz1, sizeMat);
        if (((llave[i-1]==-1 && llave[i]==-1) || llave[i-1]==0 || llave[i]==0) && i>2){
        }
        else if(llave[i+1] != 0 && i<compare+1){
            sizeMat=minSizeMat;
            fila=llave[0];
            columna=llave[1];}
    }
    return lockX;
}
