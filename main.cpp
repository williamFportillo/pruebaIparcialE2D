#include <iostream>
#include "DataFile.h"
#include "FixedSize_Register.h"
#include "KnownVarSize_Register.h"
#include "DelimiterVarSize_Register.h"
using namespace std;
int main() {
    int opc=0;
    char nombre[30];
    FixedSize_Register f;
    KnownVarSize_Register k;
    DelimiterVarSize_Register d;
    do{
        cout<<"-----Menu----\n";
        cout<<"1. FixedSize.\n";
        cout<<"2. KnownVarSize.\n";
        cout<<"3. DelimiterVarSize.\n";
        cout<<"4. Salir.\n";
        cin>>opc;
        if(opc==1){
            cout<<"Ingrese El nombre de la carpeta del archivo binario: ";
            cin>>nombre;
            f.open_file(nombre);
            f.print_register();
        }
        if(opc==2){
            cout<<"Ingrese El nombre de la carpeta del archivo binario: ";
            cin>>nombre;
            k.open_file(nombre);
            k.print_register();

        }
        if(opc==3){
            cout<<"Ingrese El nombre de la carpeta del archivo binario: ";
            cin>>nombre;
            d.open_file(nombre);
            d.print_register();
        }
    }while(opc!=4);
    return 0;
}