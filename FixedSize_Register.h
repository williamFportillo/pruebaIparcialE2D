//
// Created by WilliamPC on 1/2/2019.
//

#ifndef PRUEBAPRIMERPARCIALED2_FIXEDSIZE_REGISTER_H
#define PRUEBAPRIMERPARCIALED2_FIXEDSIZE_REGISTER_H


#include "DataFile.h"

class FixedSize_Register {
private:
    DataFile * file;
    int code;
    char * name[30];
    double salary;
    char * job[20];
public:
    void print_register( );
    char * toChar( );
    void fromChar( char * );
    void open_file ( char * );
    void write_into_file( );
    void read_from_file( int pos );
    void close_file( );
    int get_size( );
};


#endif //PRUEBAPRIMERPARCIALED2_FIXEDSIZE_REGISTER_H
