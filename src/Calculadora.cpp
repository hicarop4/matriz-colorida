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

void Calculadora::contarPontosPretos(const MyMatrix<Pixel> *matrix, MyVec<std::pair<int, int>> &coords) {
    for (int i = 0; i < matrix->getQtdLinhas(); i++) {
        for (int j = 0; j < matrix->getQtdColunas(); j++) {
            if (matrix->at(i,j).ehPreto())
                coords.push_back(std::make_pair(i, j));
        }
    }
}

double Calculadora::getMenorDistanciaTrivial(int linha, int coluna, const MyMatrix<Pixel> *matrix){
    double menorDistancia = std::numeric_limits<double>::max();
    // procura a menor distancia entre o pixel atual e os pixels pretos da matriz
    for (int i = 0; i < matrix->getQtdLinhas(); i++) {
        for (int j = 0; j < matrix->getQtdColunas(); j++) {
            bool ehPreto = matrix->at(i, j).ehPreto();
            if(ehPreto) {
                // se for preto, vai calcular a distancia e certificar se ela é a menor distancia percorrida até omomento
                menorDistancia = std::min(getDistancia(linha, coluna, i, j), menorDistancia);
            }
        }
    }
    return menorDistancia;
}

// coords deve receber um MyVec com as coordenadas dos pixels pretos
// dessa forma nao precisamos percorrer todos os pixels da matriz
 double Calculadora::getMenorDistanciaTrivialMelhorado(int linha, int coluna,
     const MyVec<std::pair<int, int>> &coords) {
     double menorDistancia = std::numeric_limits<double>::max();
     for(int i = 0; i < coords.size(); i++) {
         // certifica qual a menor distância percorrida até agora
         menorDistancia = std::min(getDistancia(linha, coluna, coords[i].first, coords[i].second), menorDistancia);
     }
     return menorDistancia;
 }

void Calculadora::gerarDistanciasTrivial(const MyMatrix<Pixel> *matrix) {
    // encontra o pixel preto mais próximo para cada pixel usando algoritmo mais intuitivo
    // e com complexidade O(n^4)
    for (int i = 0; i < matrix->getQtdLinhas(); i++) {
        for (int j = 0; j < matrix->getQtdColunas(); j++) {
             matrix->getDistancias()[i][j] = getMenorDistanciaTrivial(i,j,matrix);
        }
    }
}

void Calculadora::gerarDistanciasTrivialMelhorado(const MyMatrix<Pixel> *matrix) {
    MyVec<std::pair<int, int>> coords;
    contarPontosPretos(matrix, coords);
    // encontra o pixel preto mais próximo para cada pixel usando algoritmo
    // com complexidade O(n^3)
    for (int i = 0; i < matrix->getQtdLinhas(); i++) {
        for (int j = 0; j < matrix->getQtdColunas(); j++) {
            matrix->getDistancias()[i][j] = getMenorDistanciaTrivialMelhorado(i, j, coords);
        }
    }
}

void Calculadora::testarCalculadora() {
    assert(Calculadora::getDistancia(0, 0, 1, 1) == sqrt(2));
    std::cout << "Teste 1 passou!\n";
}
