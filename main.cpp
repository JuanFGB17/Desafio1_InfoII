#include <iostream>
#include "matrixGen.h"
#include "configKey.h"
#include "lockGen.h"
#include "verify.h"
using namespace std;




int main()
{
    int opcion=1;
    cout<<"---------- Informa2 seguridad ----------"<<endl;
    while(opcion!=0)
    {
        cout<<"1.Generar una cerradura"<<endl;
        cout<<"2.Validar una cerradura"<<endl;
        cout<<"0.Para salir del menu"<<endl;

        do{
            cout<<"Escriba el numero de la opcion querida para elegirla"<<endl;
            while (true){
                cin >> opcion;
                if (cin.fail()){
                    cout<<"Valor invalido"<<endl;
                    cin.clear();
                    while (cin.get() != '\n') {
                        continue;}}
                else
                    break;}
        }while(opcion<0 || opcion>2);

        switch(opcion){

        case 1:{
            //Recibir información
            int compare, minSizeMat, validar;
            bool found=true;
            cout << "La llave K esta conformada por (fila, columna, valores comparativos)" << endl;
            cout<<"Ejemplo con 3 valores comparativos K[4,3,1,-1,0]"<<endl;
            do{
                while (true){
                    cout << "Ingrese cuantos valores comparativos desea." << endl;
                    cin >> compare;
                    if (cin.fail()){
                        cin.clear();
                        while (cin.get() != '\n') {
                            continue;}}
                    else
                        break;}
            }while(compare<=0);

            //Procesar información
            int *llave;
            llave=configuracionKey(compare, minSizeMat);

            /*cout << endl << "Minsizemat: " << minSizeMat <<endl;
            cout << "Compare: " << compare <<endl;
            for (int i = 0; i<=compare+1; i++){
                cout << llave[i] << ' ';}
            cout<<endl;*/

            //Generar matriz

            int **matriz;
            matriz=generarMatriz(minSizeMat);

            //Generar la cerradura
            int *lockX, *rotaciones=new int[compare+1];
            lockX=lockFinder(matriz, llave, minSizeMat, compare, found, rotaciones);
            if (found){
                cout<<"La cerradura es: X[";
                for (int i = 0; i<compare+1; i++){
                cout << lockX[i];
                    if(i!=compare){
                    cout<<",";
                }
                }
                cout<<"]"<<endl;
                cout<<"Las rotaciones de cada matriz son: X[";
                for (int i = 0; i<compare+1; i++){
                    cout << rotaciones[i];
                    if(i!=compare){
                        cout<<",";
                    }
                }
                cout<<"]"<<endl;
                //Validacion regla de apertura sobre una cerradura
                do{
                        while (true){
                        cout<<"ingrese 1 para validar la cerradura o 0 para lo contrario."<<endl;
                        cin>>validar;
                        if (cin.fail()){
                            cout<<"Valor invalido"<<endl;
                            cin.clear();
                            while (cin.get() != '\n') {
                                continue;}}
                        else
                            break;}
                }while(validar!=1 && validar!=0);
                if(validar==1){
                    if (valid(llave, lockX, rotaciones, compare)){
                        cout << "La cerradura es valida" << endl << endl;
                    }
                    else{
                        cout << "La cerradura no es valida" << endl << endl;
                    }
                }
            }

            delete [] llave;
            delete [] lockX;
            delete [] rotaciones;
            }
        break;
        case 2:{

            //ingresar llave
            int compare;

            cout << "La llave K esta conformada por (fila, columna, valores comparativos)" << endl;
            cout<<"Ejemplo con 3 valores comparativos K[4,3,1,-1,0]"<<endl;
            do{
                while (true){
                    cout << "Ingrese cuantos valores comparativos desea." << endl;
                    cin >> compare;
                    if (cin.fail()){
                        cin.clear();
                        while (cin.get() != '\n') {
                            continue;}}
                    else
                        break;}
            }while(compare<=0);

            int *llave, *lockX;
            llave=configuracionKey(compare);

            //ingresar cerradura
            lockX = cerradura(compare);
            /*for (int i = 0; i<compare+1; i++){
                cout << lockX[i] << ' ';}
            cout<<endl;*/

            //validar

            if (valid(llave, lockX, compare)){
                cout << "La cerradura es valida" << endl << endl;
            }
            else{
                cout << "La cerradura no es valida" << endl << endl;
            }

            delete [] llave;
            delete [] lockX;
            }
        break;
        }
    }
    return 0;
}






