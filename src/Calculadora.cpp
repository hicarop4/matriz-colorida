//
// Created by Hícaro on 13/07/2024.
//

#include "Calculadora.h"

#include <cassert>
#include <cmath>
#include <iostream>

double Calculadora::getDistancia(const int &linha1,
                                 const int &coluna1,
                                 const int &linha2,
                                 const int &coluna2) {
    int a = abs(linha2 - linha1);
    int b = abs(coluna2 - coluna1);
    return sqrt(pow(a, 2) + pow(b, 2));
}

void Calculadora::testarCalculadora() {
    assert(Calculadora::getDistancia(0, 0, 1, 1) == sqrt(2));
    std::cout << "Teste 1 passou!\n";
}
