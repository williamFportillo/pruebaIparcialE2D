//
// Created by WilliamPC on 1/2/2019.
//

#ifndef PRUEBAPRIMERPARCIALED2_KNOWNVARSIZE_REGISTER_H
#define PRUEBAPRIMERPARCIALED2_KNOWNVARSIZE_REGISTER_H


#include "DataFile.h"

class KnownVarSize_Register {
public:
    DataFile *file;
    int sizeName;
    char * name;
    int sizeJob;
    char *job;
    int code;
    double salary;
    KnownVarSize_Register();
    void setSizeName(int size);
    int getSizeName();
    void setSizeJob(int size);
    int getSizeJob();
    void print_register( );
    char * toChar( );
    void fromChar(char *);
    void open_file (char *);
    void write_into_file();
    void read_from_file( int pos );
    void close_file( );
    int get_size(  );
};

#endif //PRUEBAPRIMERPARCIALED2_KNOWNVARSIZE_REGISTER_H
