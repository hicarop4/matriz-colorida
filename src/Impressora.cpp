//
// Created by Hícaro on 14/07/2024.
//

#include "Impressora.h"

void Impressora::imprimirDistancias(MyMatrix<double> *distancias) {
    for (int i = 0; i < distancias->getQtdLinhas(); i++) {
        for (int j = 0; j < distancias->getQtdColunas(); j++) {
            cout << std::round(distancias->at(i, j)) << " ";
        }
        cout << "\n";
    }
}

void Impressora::imprimirResumo(MyMatrix<double> *distancias) {
    unsigned long long soma = 0;
    for (int i = 0; i < distancias->getQtdLinhas(); i++) {
        for (int j = 0; j < distancias->getQtdColunas(); j++) {
            soma += std::round(distancias->at(i, j));
        }
    }
    cout << soma << "\n";
}


// template<typename T>
// void MyMatrix<T>::imprimirDistancias() const {
//     for (int i = 0; i < this->getQtdLinhas(); i++) {
//         for (int j = 0; j < this->getQtdColunas(); j++) {
//             cout << std::round(this->data[i][j]) << " ";
//         }
//         cout << "\n";
//     }
// }
//
// template<typename T>
// void MyMatrix<T>::imprimirResumo() const {
//
//     unsigned long long soma = 0;
//     for (int i = 0; i < qtdLinhas; i++) {
//         for (int j = 0; j < qtdColunas; j++) {
//             soma += std::round(data[i][j]);
//         }
//     }
//     cout << soma << endl;
// }