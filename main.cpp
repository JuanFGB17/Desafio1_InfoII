#include <iostream>
#include <matrixGen.h>
#include <configKey.h>
#include <lockGen.h>
using namespace std;




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
    cout<<endl;
    //Generar matriz


    int **matriz, *lockX;
    matriz=generarMatriz(minSizeMat);




    //Generar la cerradura

    lockX=lockFinder(matriz, llave, minSizeMat, compare);
    for (int i = 0; i<compare+1; i++){
        cout << lockX[i] << ' ';}
    cout<<endl;
    liberarMatriz(matriz, minSizeMat);
    delete [] llave;
    delete [] lockX;
    return 0;
}






