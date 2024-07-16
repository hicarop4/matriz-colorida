//
// Created by Hícaro on 14/07/2024.
//

#ifndef IMPRESSORA_H
#define IMPRESSORA_H
#include "MyMatrix.h"
#include "Pixel.h"


class Impressora {
public:
    static void imprimirDistancias(MyMatrix<double> *distancias);
    static void imprimirResumo(MyMatrix<double> *distancias);
    static void imprimirImagem(const string& tipoDeArquivo, MyMatrix<Pixel> *imagem);

};


#endif //IMPRESSORA_H
