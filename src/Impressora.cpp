//
// Created by Hícaro on 14/07/2024.
//

#include "../includes/Impressora.h"
#include <complex>

// imprime a matriz de distancia arredondando seus valores
void Impressora::imprimirDistancias(MyMatrix<double> *distancias) {
    for (int i = 0; i < distancias->getQtdLinhas(); i++) {
        for (int j = 0; j < distancias->getQtdColunas(); j++) {
            cout << std::round(distancias->at(i, j)) << " ";
        }
        cout << "\n";
    }
}

// soma os valores arredondados das distancias e imprime o resultado
void Impressora::imprimirResumo(MyMatrix<double> *distancias) {
    unsigned long long soma = 0;
    for (int i = 0; i < distancias->getQtdLinhas(); i++) {
        for (int j = 0; j < distancias->getQtdColunas(); j++) {
            soma += std::round(distancias->at(i, j));
        }
    }
    cout << soma << "\n";
}

// imprime uma matriz de pixel com uma saída formatada para uma imagem .ppm
void Impressora::imprimirImagem(const string& tipoDeArquivo, MyMatrix<Pixel> *imagem) {
    cout << tipoDeArquivo << "\n";
    cout << imagem->getQtdColunas() << " " << imagem->getQtdLinhas() << "\n";
    cout << 255 << "\n";
    imagem->imprimir();
}
