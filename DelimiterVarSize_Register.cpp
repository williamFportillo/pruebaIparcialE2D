//
// Created by WilliamPC on 1/2/2019.
//

#include <iostream>
#include <fstream>
#include <cstring>

#include "DelimiterVarSize_Register.h"
using namespace std;

void DelimiterVarSize_Register::open_file ( char * files){
    char *f=new char[strlen(files)];
    strcpy(f,files);
    file->abrir();
    cout<<"--------------------\n";
}

void DelimiterVarSize_Register:: print_register(){
    file->archivo->seekg(0, ios::beg);
    DelimiterVarSize_Register actual;
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
char *DelimiterVarSize_Register:: toChar( ){
    char* ret = new char[get_size()];
    string c = to_string(code);
    string s = to_string(salary);
    strcat(ret, name);
    strcat(ret, ";");
    strcat(ret, c.c_str());
    strcat(ret, ";");
    strcat(ret, job);
    strcat(ret, ";");
    strcat(ret, s.c_str());
    strcat(ret, "\n");
    return ret;
}

void DelimiterVarSize_Register::read_from_file( int pos ){
    file->leer(pos, get_size());
}
void DelimiterVarSize_Register::close_file( ){
    file->cerrar();
}
int DelimiterVarSize_Register::get_size(  ){
    return sizeof(code)+ sizeof(job)+ sizeof(name)+ sizeof(salary);
}
void DelimiterVarSize_Register::fromChar(char * c) {
    string temporal = "";
    int i = 0;
    int tamActual = 0;
    int posActual = 0;
    bool recorrido = false;
    char n[30];
    char j[20];
    while (!recorrido) {
        if (c[i] == ';') {
            if (posActual == 0) {
                n=new char[strlen(name)];
                strcpy(n,name);
                strcpy(n, (char *) &temporal);
                posActual++;
            } else if (posActual == 1) {
                code = stoi(temporal);
                posActual++;
            } else if (posActual == 2) {
                j=new char[strlen(job)];
                strcpy(j,job);
                strcpy(j, (char *) &temporal);
                recorrido = true;
            } else if (posActual == 3) {
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