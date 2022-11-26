// Compilação: g++ -Wall -c -o Fantasma.o Fantasna.cpp
#include "Fantasma.h"
#include <iostream>

int Fantasma::getX() { // Tem que especificar o namespace(::)
    return x;
}

Fantasma::Fantasma() {
    x = 0;
    y = 0;
    status=VIVO;
    sprite='c';
    cerr << "[novo fantasma]" << endl; // cerr é a saída de erro (costuma ser mais rápida)
                                        // endl é quebra de linha (tem o mesmo efeito que \n) 
}

Fantasma::~Fantasma() {
    cerr << "[tchau fantasma]" << endl;
}