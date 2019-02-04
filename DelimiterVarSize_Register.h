//
// Created by WilliamPC on 1/2/2019.
//

#ifndef PRUEBAPRIMERPARCIALED2_DELIMITERVARSIZE_REGISTER_H
#define PRUEBAPRIMERPARCIALED2_DELIMITERVARSIZE_REGISTER_H


#include "DataFile.h"

class DelimiterVarSize_Register {
private:
    DataFile * file;
    int code;
    char * name;
    double salary;
    char * job;
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


#endif //PRUEBAPRIMERPARCIALED2_DELIMITERVARSIZE_REGISTER_H
