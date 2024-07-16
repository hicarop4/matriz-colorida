//
// Created by Hícaro on 14/07/2024.
//

#include "src/Impressora.h"

#include <complex>

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

void Impressora::imprimirImagem(const string& tipoDeArquivo, MyMatrix<Pixel> *imagem) {
    cout << tipoDeArquivo << "\n";
    cout << imagem->getQtdColunas() << " " << imagem->getQtdLinhas() << "\n";
    cout << 255 << "\n";
    imagem->imprimir();
}
