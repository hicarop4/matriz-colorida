//
// Created by Hícaro on 14/07/2024.
//

#include "GeradorImagem.h"

MyMatrix<Pixel>* GeradorImagem::gerarImagem(MyMatrix<Pixel> *matrix, MyMatrix<double> *distancias) {
    MyMatrix<Pixel> *imagem = new MyMatrix<Pixel>(matrix->getQtdColunas(), matrix->getQtdLinhas());
    double maiorDistancia = encontrarMaiorDistancia(distancias);

    for (int i = 0; i < imagem->getQtdLinhas(); i++) {
        for (int j = 0; j < imagem->getQtdColunas(); j++) {

        }
    }
    return imagem;
}

int GeradorImagem::encontrarMaiorDistancia(const MyMatrix<double> *distancias) {
    double maiorDistancia = std::numeric_limits<double>::min();
    for (int i = 0; i < distancias->getQtdLinhas(); i++) {
        for (int j = 0; j < distancias->getQtdColunas(); j++) {
            maiorDistancia = std::max(distancias->at(i, j), maiorDistancia);
        }
    }
    return maiorDistancia;
}
