#include <iostream>
#include "matrixGen.h"

using namespace std;

bool valid(int *llave, int *lock)
{

    //Validación 2 -------------------------
   /* Llave = [4,3,-1,1,0];
    Rotaciones=[0,1,0,1];
    Lock=[5,5,5,5];
    Bool valid=true;

    Fila=llave[0];
    Columna=llave[1];

    Matriz=GenerarMatriz(lock[0]);
    Pin=Matriz[fila][columna];


    For (int i=2;i<compare+1;i++){
        Cont=0;
        If(llave[i]==1){
            Matriz1=GenerarMatriz(lock[cont]);
            If(cont!=0&&lock[cont]>lock[cont-1]){
                Fila+=1;
                Column+=1;
            }
            For (int rot=0;rot<rotaciones[cont];rot++){
                Matriz1=RotarMatriz(rot);
                Pin1=matriz1[fila][columna];
                ImprimirMatriz(matriz1,lock[cont])
                    Cout<<pin<<' '<<pin1<<endl;
            }
            If(pin<pin1){
                Valid=false;
                Break;
            }
            Cont++;
        }
        Else if(llave[i]==-1){
            Matriz1=GenerarMatriz(lock[cont]);
            If(cont!=0&&lock[cont]>lock[cont-1]){
                Fila+=1;
                Column+=1;
            }
            For (int rot=0;rot<rotaciones[cont];rot++){
                Matriz1=RotarMatriz(rot);
                Pin1=matriz1[fila][columna];
                ImprimirMatriz(matriz1,lock[cont])
                    Cout<<pin<<' '<<pin1<<endl;
            }
            If(pin>pin1){
                Valid=false;
                Break;
            }
            Cont++;
        }
        Else if(llave[i]==-1){
            Matriz1=GenerarMatriz(lock[cont]);
            If(cont!=0&&lock[cont]>lock[cont-1]){
                Fila+=1;
                Column+=1;
            }
            For (int rot=0;rot<rotaciones[cont];rot++){
                Matriz1=RotarMatriz(rot);
                Pin1=matriz1[fila][columna];
                ImprimirMatriz(matriz1,lock[cont])
                    Cout<<pin<<' '<<pin1<<endl;
            }
            If(pin!=pin1){
                Valid=false;
                Break;
            }
            Cont++;
        }
        If(valid==true){
            Cout<<"La cerradura es valida"<<endl;
            Return true;
        }
    }
*/
    return true;
}

bool valid(int *llave, int *lock, int* rotaciones, int compare)
{
    /*llave = [4,3,-1,1,0];
    rotaciones=[0,1,0,1];
    lock=[5,5,5,5];*/
    bool valid=true;
    int **matriz, **matriz1, pin1, pin, cont, rot;

    int fila=llave[0];
    int columna=llave[1];

    matriz = generarMatriz(lock[0]);
    pin=matriz[fila][columna];
    imprimirMatriz(matriz,lock[0]);
    cout<<"inicio "<<pin<<endl;
    int tamano;

    cont=1;
    for (int i=2;i<=compare+1;i++){

        tamano=lock[cont];
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
                cout<<"no roto "<<endl;
            }

            for (rot=1;rot<=rotaciones[cont];rot++){
                rotarMatriz(matriz1,lock[cont]);
                pin1=matriz1[fila][columna];
                cout<<"roto "<<endl;
            }

            imprimirMatriz(matriz1,lock[cont]);
            cout<<pin<<' '<<pin1<<endl;

            if(pin<pin1 || pin==pin1){
                valid=false;
                break;
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
                cout<<"no roto"<<endl;
            }

            for (rot=1;rot<=rotaciones[cont];rot++){
                rotarMatriz(matriz1,lock[cont]);
                pin1=matriz1[fila][columna];
                cout<<"roto"<<endl;
            }

            imprimirMatriz(matriz1,lock[cont]);
            cout<<pin<<' '<<pin1<<endl;

            if(pin>pin1 || pin==pin1){
                valid=false;
                break;
            }
        }
        else if(llave[i]==0){

            matriz1=generarMatriz(lock[cont]);

            if(rotaciones[cont]==0){
                pin1=matriz1[fila][columna];
                cout<<"no roto"<<endl;
            }

            for (rot=1;rot<=rotaciones[cont];rot++){
                rotarMatriz(matriz1,lock[cont]);
                pin1=matriz1[fila][columna];
                cout<<"roto"<<endl;
            }

            imprimirMatriz(matriz1,lock[cont]);
            cout<<pin<<' '<<pin1<<endl;

            if(pin!=pin1){
                valid=false;
                break;
            }
        }
        rot=1;
        cont++;
        pin=pin1;
        }
    if(valid==true){
        cout<<"La cerradura es valida"<<endl;
        return true;
    }
    return true;
}
