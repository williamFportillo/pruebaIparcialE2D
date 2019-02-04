//
// Created by WilliamPC on 1/2/2019.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include "KnownVarSize_Register.h"

using namespace std;

void KnownVarSize_Register::setSizeName(int size){
    sizeName = size;
}
int KnownVarSize_Register::getSizeName(){
    return sizeName;
}
void KnownVarSize_Register::setSizeJob(int size){
    sizeJob=size;
}
int KnownVarSize_Register::getSizeJob(){
    return sizeJob;
}
KnownVarSize_Register::KnownVarSize_Register() {
    name = new char[getSizeName()];
    job = new char[getSizeJob()];
}
void KnownVarSize_Register::open_file ( char *files ){
    char *f=new char[strlen(files)];
    strcpy(f,files);
    file->abrir();
    cout<<"--------------------\n";
}

void KnownVarSize_Register::print_register(){
    file->archivo->seekg(0, ios::beg);
    KnownVarSize_Register actual;
    file->archivo->read(reinterpret_cast<char *>(&actual) ,get_size());
    while (!file->archivo->eof()){
        cout<<"***Informacion***\n";
        cout << "Nombre: " << actual.name << "\n";
        cout <<"Codigo: " << actual.code << "\n";
        cout <<"Trabajo: " << actual.job<< "\n";
        cout<<"Salario: " << actual.salary<<"\n";
        cout <<"\n-------------------------------------------------------------------\n";
    }
    file->archivo->read(reinterpret_cast<char *>(&actual) ,get_size());
    file->cerrar();
}

void KnownVarSize_Register::read_from_file( int pos ){
    file->leer(pos, get_size());
}
void KnownVarSize_Register::close_file( ){
    file->cerrar();
}
int KnownVarSize_Register::get_size(  ){
    return sizeName+sizeof(code)+ sizeof(salary)+sizeJob;
}


char *KnownVarSize_Register:: toChar(){
    int pos = 0;
    char salto = '\n';
    char separacion = ' ';
    int longitud = get_size();
    char *nuevo = new char[longitud];
    int tamano_nombre = strlen(name);
    memcpy(&nuevo[pos], name, tamano_nombre);
    pos =pos+ tamano_nombre;
    memcpy(&nuevo[pos], &separacion, 1);
    pos++;

    memcpy(&nuevo[pos], (char*)&code, sizeof(int));
    pos = pos+ 4;
    memcpy(&nuevo[pos], &separacion, 1);
    pos++;

    int tamano_trabajo = strlen(job);
    memcpy(&nuevo[pos], job, tamano_trabajo);
    pos =pos+ tamano_trabajo;
    memcpy(&nuevo[pos], &separacion, 1);
    pos++;

    memcpy(&nuevo[pos], (char*)&salary, sizeof(double));
    pos =pos+ sizeof(double);
    memcpy(&nuevo[pos], &salto, 1);
    return nuevo;
}

void KnownVarSize_Register::fromChar(char *c) {
    string temporal = "";
    int i = 0;
    int tamActual = 0;
    int posActual = 0;
    bool recorrido = false;
    char n[30];
    char j[20];
    while(!recorrido) {
        if (c[i] == '\n') {
            if (posActual == 0) {
                n=new char[strlen(name)];
                strcpy(n,name);
                strcpy(n, (char*)&temporal);
                posActual++;
            }
            else if (posActual == 1) {
                code=stoi(temporal);
                posActual++;
            }
            else if (posActual == 2) {
                j=new char[strlen(job)];
                strcpy(j,job);
                strcpy(job, (char*)&temporal);
                recorrido = true;
            }
            else if (posActual == 3) {
                salary = stoi(temporal);
                posActual++;
            }

            temporal = "";
            tamActual = 0;
        }
        temporal = temporal+ c[i];
        tamActual++;
    }
    cout << "Nombre: " << n << "\n";
    cout << "Codigo: " << code << "\n";
    cout << "Trabajo: " << j << "\n";
    cout << "Salario: " << salary << "\n";


}
