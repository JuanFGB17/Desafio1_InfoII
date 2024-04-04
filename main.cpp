#include <iostream>
#include <matrixGen.h>
#include <configKey.h>
#include <lockGen.h>
using namespace std;




int main()
{
    //Recibir información
    int compare, minSizeMat;
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

    cout << endl << "Minsizemat: " << minSizeMat <<endl;
    cout << "Compare: " << compare <<endl;
    for (int i = 0; i<=compare+1; i++){
        cout << llave[i] << ' ';}
    cout<<endl;

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
    }
    //Validacion regla de apertura sobre una cerradura




    liberarMatriz(matriz, minSizeMat);
    delete [] llave;
    delete [] lockX;
    delete [] rotaciones;
    return 0;
}






