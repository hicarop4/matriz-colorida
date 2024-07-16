//
// Created by Hícaro on 14/07/2024.
//

#include "src/GeradorImagem.h"
#include "src/hsv2rgb.h"
#include <limits>

MyMatrix<Pixel>* GeradorImagem::gerarImagem(MyMatrix<double> *distancias) {
    MyMatrix<Pixel> *imagem = new MyMatrix<Pixel>(distancias->getQtdColunas(), distancias->getQtdLinhas());
    double maiorDistancia = encontrarMaiorDistancia(distancias);

    for (int i = 0; i < imagem->getQtdLinhas(); i++) {
        for (int j = 0; j < imagem->getQtdColunas(); j++) {
            double distancia = distancias->at(i, j);
            imagem->at(i, j) = geraCorDist(distancia/maiorDistancia);
        }
    }
    return imagem;
}

double GeradorImagem::encontrarMaiorDistancia(const MyMatrix<double> *distancias) {
    double maiorDistancia = std::numeric_limits<double>::min();
    for (int i = 0; i < distancias->getQtdLinhas(); i++) {
        for (int j = 0; j < distancias->getQtdColunas(); j++) {
            maiorDistancia = std::max(distancias->at(i, j), maiorDistancia);
        }
    }
    return maiorDistancia;
}
