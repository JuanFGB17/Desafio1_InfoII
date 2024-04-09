#include <iostream>
#include "configKey.h"
using namespace std;

int *configuracionKey(int compare, int &minSizeMat) {

    int k=0;
    int *llave = new int[compare + 2];
    do{
        while (true){
            cout << "Ingrese una fila mayor o igual a 1" << endl;
            cin >> k;
            if (cin.fail()){
                cin.clear();
                while (cin.get() != '\n') {
                    continue;}}
            else
                break;}
    }while(k<1);
    k-=1;
    minSizeMat=k;
    llave[0] = k;
    do{
        while (true){
            cout << "Ingrese una columna mayor o igual a 1" << endl;
            cin >> k;
            if (cin.fail()){
                cin.clear();
                while (cin.get() != '\n') {
                    continue;}}
            else
                break;}

    }while(k<1);
    k-=1;
    if(minSizeMat==1 && k==1){
       minSizeMat = 5;
    }
    if (minSizeMat<k)
        minSizeMat=k;
    if (minSizeMat%2==0)
        minSizeMat++;
    else if(minSizeMat!=1 && k!=1)
        minSizeMat += 2;
    llave[1] = k;
    cout << "Ingrese los valores comparativos (-1, 0, 1)" << endl;
    for (int i = 2; i<=compare+1; i++){
        do{
            while (true){
                cout << "Valor comparativo" << endl;
                cin >> k;
                if (cin.fail()){
                    cin.clear();
                    while (cin.get() != '\n') {
                        continue;}}
                else
                    break;}
        }while(k!=-1 && k!=1 && k!=0);
        llave[i] = k;
    }
    return llave;
}

int *configuracionKey(int compare) {

    int k=0,fila;
    int *llave = new int[compare + 2];
    do{
        while (true){
            cout << "Ingrese una fila mayor o igual a 1" << endl;
            cin >> k;
            if (cin.fail()){
                cin.clear();
                while (cin.get() != '\n') {
                    continue;}}
            else
                break;}
    }while(k<1);
    k-=1;
    fila=k;
    llave[0] = k;
    do{
        while (true){
            cout << "Ingrese una columna mayor o igual a 1" << endl;
            cin >> k;
            if (cin.fail()){
                cin.clear();
                while (cin.get() != '\n') {
                    continue;}}
            else
                break;}
    }while(k<1);
    k-=1;
    llave[1] = k;
    cout << "Ingrese los valores comparativos (-1, 0, 1)" << endl;
    for (int i = 2; i<=compare+1; i++){
        do{
            while (true){
                cout << "Valor comparativo" << endl;
                cin >> k;
                if (cin.fail()){
                    cin.clear();
                    while (cin.get() != '\n') {
                        continue;}}
                else
                    break;}
        }while(k!=-1 && k!=1 && k!=0);
        llave[i] = k;
    }
    return llave;
}
