//
// Created by WilliamPC on 1/2/2019.
//

#include <cstring>
#include <iostream>
#include "DataFile.h"
#include "FixedSize_Register.h"

using namespace std;

void FixedSize_Register::open_file(char *files ) {
    char *f=new char[strlen(files)];
    strcpy(f,files);
    file->abrir();
    cout<<"--------------------\n";
}

void FixedSize_Register::print_register() {
    file->archivo->seekg(0, ios::beg);
    FixedSize_Register actual;
    file->archivo->read(reinterpret_cast<char *>(&actual),get_size());
    while (!file->archivo->eof()){
        cout<<"***Informacion***\n";
        cout << "Nombre: " << actual.name << "\n";
        cout <<"Codigo: " << actual.code << "\n";
        cout <<"Trabajo: " << actual.job<< "\n";
        cout<<"Salario: " << actual.salary<<"\n";
        cout <<"\n-------------------------------------------------------------------\n";
        file->archivo->read(reinterpret_cast<char *>(&actual) ,get_size());
    }

    file->cerrar();

}


void FixedSize_Register::close_file() {
    file->cerrar();
}
int FixedSize_Register::get_size() {
    return sizeof(code)+ sizeof(name)+sizeof(salary)+ sizeof(job);
}

void FixedSize_Register::read_from_file(int pos) {
    file->leer(pos,get_size());
}

char * FixedSize_Register::toChar() {
    int pos = 0;
    char salto = '\n';
    char separacion = ' ';
    int longitud = get_size();
    char *nuevo = new char[longitud];

    memcpy(&nuevo[pos], name, 30);
    pos = pos+ 30;
    memcpy(&nuevo[pos], &separacion, 1);
    pos++;
    memcpy(&nuevo[pos], (char*)&code, sizeof(int));
    pos = pos+4;
    memcpy(&nuevo[pos], &separacion, 1);
    pos++;
    memcpy(&nuevo[pos], job, 20);
    pos = pos+ 20;
    memcpy(&nuevo[pos], &separacion, 1);
    pos++;
    memcpy(&nuevo[pos], (char*)&salary, sizeof(double));
    pos = pos+ sizeof(double);
    memcpy(&nuevo[pos], &salto, 1);
    return nuevo;
}

void FixedSize_Register::fromChar(char * c){
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
                strcpy( n, (char *)&temporal);
                posActual++;
            }
            else if (posActual == 1) {
                code=stoi(temporal);
                posActual++;
            }
            else if (posActual == 2) {
                 j=new char[strlen(job)];
                strcpy(j,job);
                strcpy(j, (char*)&temporal);
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