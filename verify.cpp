#include <iostream>
#include "matrixGen.h"

using namespace std;

bool valid(int *llave, int *lock, int compare)
{
    int **matriz1, pin1, pin, cont, rot;
    int fila=llave[0];
    int columna=llave[1];

    if (llave[0]>=lock[0] || llave[1]>=lock[0]){
        return false;
    }
    else{
        matriz1 = generarMatriz(lock[0]);
        pin=matriz1[fila][columna];
        cout<< endl << "La matriz siguiente roto 0 veces." <<endl;
        cout << endl;
        imprimirMatriz(matriz1,lock[0]);
        cout << endl;
        liberarMatriz(matriz1,lock[0]);
        cout << "En la fila " << fila+1 << " y la columna " << columna+1 << " el valor es: " << pin <<endl;
    }
    if (pin==0){
        return false;
    }

        cont=1;
        for (int i=2;i<=compare+1;i++){

            if(llave[i]==1){

                matriz1=generarMatriz(lock[cont]);
                //Si la matriz aumenta de tamaño se actualiza fila y columna
                if(cont!=0&&lock[cont]>lock[cont-1]){

                    fila+=(lock[cont]-lock[cont-1])/2;
                    columna+=(lock[cont]-lock[cont-1])/2;
                }
                //Si la matriz disminuye de tamaño se actualiza fila y columna
                else if(cont!=0&&lock[cont]<lock[cont-1]){

                    fila-=(lock[cont-1]-lock[cont])/2;
                    columna-=(lock[cont-1]-lock[cont])/2;
                }
                if (fila>=lock[cont] || columna>=lock[cont]){
                    return false;
                }
                for (rot=0;rot<3;rot++){
                    if (pin>matriz1[fila][columna]){
                        pin1=matriz1[fila][columna];
                        cout<< endl << "La matriz siguiente roto " << rot << " veces." <<endl;
                        break;}
                    else{
                        rotarMatriz(matriz1,lock[cont]);
                        pin1=matriz1[fila][columna];
                    }
                }
                cout << endl;
                imprimirMatriz(matriz1,lock[cont]);
                cout << endl;
                cout<< "El valor anterior es " << pin << ", el valor actual es " <<pin1<<endl;
                cout<< "El valor actual se encuentra en la fila " << fila+1 << " y la columna " << columna+1 <<endl;

                if(pin<pin1 || pin==pin1){
                    liberarMatriz(matriz1,lock[cont]);
                    return false;
                }
            }
            else if(llave[i]==-1){

                matriz1=generarMatriz(lock[cont]);
                //Si la matriz aumenta de tamaño se actualiza fila y columna
                if(cont!=0&&lock[cont]>lock[cont-1]){

                    fila+=(lock[cont]-lock[cont-1])/2;
                    columna+=(lock[cont]-lock[cont-1])/2;
                }
                //Si la matriz disminuye de tamaño se actualiza fila y columna
                else if(cont!=0&&lock[cont]<lock[cont-1]){

                    fila-=(lock[cont-1]-lock[cont])/2;
                    columna-=(lock[cont-1]-lock[cont])/2;
                }
                if (fila>=lock[cont] || columna>=lock[cont]){
                    return false;
                }
                for (rot=0;rot<3;rot++){
                    if (pin<matriz1[fila][columna]){
                        pin1=matriz1[fila][columna];
                        cout<< endl << "La matriz siguiente roto " << rot << " veces." <<endl;
                        break;}
                    else{
                        rotarMatriz(matriz1,lock[cont]);
                        pin1=matriz1[fila][columna];
                    }
                }
                cout << endl;
                imprimirMatriz(matriz1,lock[cont]);
                cout << endl;
                cout<< "El valor anterior es " << pin << ", el valor actual es " <<pin1<<endl;
                cout<< "El valor actual se encuentra en la fila " << fila+1 << " y la columna " << columna+1 <<endl;

                if(pin>pin1 || pin==pin1){
                    liberarMatriz(matriz1,lock[cont]);
                    return false;
                }
            }
            else if(llave[i]==0){

                matriz1=generarMatriz(lock[cont]);
                //Si la matriz aumenta de tamaño se actualiza fila y columna
                if(cont!=0&&lock[cont]>lock[cont-1]){

                    fila+=(lock[cont]-lock[cont-1])/2;
                    columna+=(lock[cont]-lock[cont-1])/2;
                }
                //Si la matriz disminuye de tamaño se actualiza fila y columna
                else if(cont!=0&&lock[cont]<lock[cont-1]){

                    fila-=(lock[cont-1]-lock[cont])/2;
                    columna-=(lock[cont-1]-lock[cont])/2;
                }
                if (fila>=lock[cont] || columna>=lock[cont]){
                    return false;
                }
                for (rot=0;rot<3;rot++){
                    if (pin==matriz1[fila][columna]){
                        pin1=matriz1[fila][columna];
                        cout<< endl << "La matriz siguiente roto " << rot << " veces." <<endl;
                        break;}
                    else{
                        rotarMatriz(matriz1,lock[cont]);
                        pin1=matriz1[fila][columna];
                    }
                }
                cout << endl;
                imprimirMatriz(matriz1,lock[cont]);
                cout << endl;
                cout<< "El valor anterior es " << pin << ", el valor actual es " <<pin1<<endl;
                cout<< "El valor actual se encuentra en la fila " << fila+1 << " y la columna " << columna+1 <<endl;

                if(pin!=pin1 || pin==0 || pin1==0){
                    liberarMatriz(matriz1,lock[cont]);
                    return false;
                }
            }
            liberarMatriz(matriz1,lock[cont]);
            rot=0;
            cont++;
            pin=pin1;
        }
    return true;
}

bool valid(int *llave, int *lock, int* rotaciones, int compare)
{
    int **matriz1, pin1, pin, cont, rot;
    int fila=llave[0];
    int columna=llave[1];

    if (llave[2]==1 && llave[0]==0 && llave[1]<lock[0]){
        matriz1 = generarMatriz(lock[0]);
        rotarMatriz(matriz1,lock[0]);
        pin=matriz1[fila][columna];
        cout<< endl << "La matriz siguiente roto " << rotaciones[0] << " veces." << endl << endl;
        imprimirMatriz(matriz1,lock[0]);
        cout<< endl << "En la fila " << fila+1 << " y la columna " << columna+1 << " el valor es: " << pin <<endl;
        liberarMatriz(matriz1,lock[0]);
        cout<<"inicio "<<pin<<endl;
    }
    else{
        matriz1 = generarMatriz(lock[0]);
        pin=matriz1[fila][columna];
        cout<< endl << "La matriz siguiente roto " << rotaciones[0] << " veces." << endl << endl;
        imprimirMatriz(matriz1,lock[0]);
        cout<< endl << "En la fila " << fila+1 << " y la columna " << columna+1 << " el valor es: " << pin <<endl;
        liberarMatriz(matriz1,lock[0]);
    }

    cont=1;
    for (int i=2;i<=compare+1;i++){

        if(llave[i]==1){

            matriz1=generarMatriz(lock[cont]);
            //Si la matriz aumenta de tamaño se actualiza fila y columna
            if(cont!=0&&lock[cont]>lock[cont-1]){

                fila+=(lock[cont]-lock[cont-1])/2;
                columna+=(lock[cont]-lock[cont-1])/2;
            }
            //Si la matriz disminuye de tamaño se actualiza fila y columna
            if(cont!=0&&lock[cont]<lock[cont-1]){

                fila-=1;
                columna-=1;
            }

            if(rotaciones[cont]==0){
                pin1=matriz1[fila][columna];
            }
            for (rot=1;rot<=rotaciones[cont];rot++){
                rotarMatriz(matriz1,lock[cont]);
                pin1=matriz1[fila][columna];

            }
            cout<< endl << "La matriz siguiente roto " << rotaciones[cont] << " veces." << endl << endl;
            imprimirMatriz(matriz1,lock[cont]);
            cout<< endl << "El valor anterior es " << pin << ", el valor actual es " << pin1 << endl;
            cout<< "El valor actual se encuentra en la fila " << fila+1 << " y la columna " << columna+1 <<endl;

            if(pin<pin1 || pin==pin1){
                liberarMatriz(matriz1,lock[cont]);
                return false;
            }
        }
        else if(llave[i]==-1){

            matriz1=generarMatriz(lock[cont]);
            //Si la matriz aumenta de tamaño se actualiza fila y columna
            if(cont!=0&&lock[cont]>lock[cont-1]){

                fila+=(lock[cont]-lock[cont-1])/2;
                columna+=(lock[cont]-lock[cont-1])/2;
            }
            //Si la matriz disminuye de tamaño se actualiza fila y columna
            if(cont!=0&&lock[cont]<lock[cont-1]){

                fila-=1;
                columna-=1;
            }

            if(rotaciones[cont]==0){
                pin1=matriz1[fila][columna];
            }
            for (rot=1;rot<=rotaciones[cont];rot++){
                rotarMatriz(matriz1,lock[cont]);
                pin1=matriz1[fila][columna];

            }
            cout<< endl << "La matriz siguiente roto " << rotaciones[cont] << " veces." << endl << endl;
            imprimirMatriz(matriz1,lock[cont]);
            cout<< endl << "El valor anterior es " << pin << ", el valor actual es " << pin1 << endl;
            cout<< "El valor actual se encuentra en la fila " << fila+1 << " y la columna " << columna+1 <<endl;

            if(pin>pin1 || pin==pin1){
                liberarMatriz(matriz1,lock[cont]);
                return false;
            }
        }
        else if(llave[i]==0){

            matriz1=generarMatriz(lock[cont]);

            if(rotaciones[cont]==0){
                pin1=matriz1[fila][columna];
            }
            for (rot=1;rot<=rotaciones[cont];rot++){
                rotarMatriz(matriz1,lock[cont]);
                pin1=matriz1[fila][columna];

            }
            cout<< endl << "La matriz siguiente roto " << rotaciones[cont] << " veces." << endl << endl;
            imprimirMatriz(matriz1,lock[cont]);
            cout<< endl << "El valor anterior es " << pin << ", el valor actual es " << pin1 << endl;
            cout<< "El valor actual se encuentra en la fila " << fila+1 << " y la columna " << columna+1 <<endl;

            if(pin!=pin1){
                liberarMatriz(matriz1,lock[cont]);
                return false;
            }
        }
        liberarMatriz(matriz1,lock[cont]);
        rot=1;
        cont++;
        pin=pin1;
        }
    return true;
}

int *cerradura(int compare){
    int *lockX= new int [compare+1];
    int X=0;

    for (int i = 0; i<compare+1; i++){

        do{
            while (true){
                cout << "Ingrese un tamanio n impar diferente de 1" << endl;
                cin >> X;
                if (cin.fail()){
                    cout << "Valor invalido" << endl;
                    cin.clear();
                    while (cin.get() != '\n') {
                        continue;}}
                else
                    break;}
        }while(X<2 || X%2==0);

        lockX[i] = X;
    }

    return lockX;
}

