#include <iostream>

using namespace std;

int main()
{
    int size, k=0, minsizemat;
    cout << "La llave k esta conformada por (fila, columna, valores comparativos)" << endl;
    do{
        while (true){
            cout << "Cuantos valores comparativos desea ingresar" << endl;
            cin >> size;
            if (cin.fail()){
                cin.clear();
                while (cin.get() != '\n') {
                    continue;}}
            else
                break;}
    }while(size<=0);
    int *llave = new int[size + 2];
    do{
        while (true){
            cout << "Ingrese una fila mayor o igual a 0" << endl;
            cin >> k;
            if (cin.fail()){
                cin.clear();
                while (cin.get() != '\n') {
                    continue;}}
            else
                break;}
    }while(k<0);
    minsizemat=k;
    llave[0] = k;
    do{
        while (true){
            cout << "Ingrese una columna mayor o igual a 0" << endl;
            cin >> k;
            if (cin.fail()){
                cin.clear();
                while (cin.get() != '\n') {
                    continue;}}
            else
                break;}
    }while(k<0);
    if (minsizemat<k)
        minsizemat=k;
    if (minsizemat%2==0)
        minsizemat++;
    else
        minsizemat += 2;
    llave[1] = k;
    cout << "Ingrese los valores comparativos (-1, 0, 1)" << endl;
    for (int i = 2; i<=size+1; i++){
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
    for (int i = 0; i<=size+1; i++){
        cout << llave[i] << ' ';
    }
    delete [] llave;
    cout << endl << "Minsizemat: " << minsizemat <<endl;
    cout << "Comparaciones: " << size <<endl;
    return 0;
}
