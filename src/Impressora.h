//
// Created by Hícaro on 14/07/2024.
//

#ifndef IMPRESSORA_H
#define IMPRESSORA_H
#include "MyMatrix.h"


class Impressora {
public:
    static void imprimirDistancias(MyMatrix<double> *distancias);
    static void imprimirResumo(MyMatrix<double> *distancias);
};


#endif //IMPRESSORA_H
