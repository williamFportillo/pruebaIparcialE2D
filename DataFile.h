//
// Created by WilliamPC on 1/2/2019.
//

#ifndef PRUEBAPRIMERPARCIALED2_DATAFILE_H
#define PRUEBAPRIMERPARCIALED2_DATAFILE_H


#include <fstream>

class DataFile
{
public:
    DataFile();
    DataFile(char *);
    void abrir();
    void cerrar();
    void escribir(char*, int, int);
    char* leer(int, int);
    void setArchivo(char*);
    char *direccion;
    std::fstream *archivo;
};



#endif //PRUEBAPRIMERPARCIALED2_DATAFILE_H
