//
// Created by Hícaro on 13/07/2024.
//

#ifndef CALCULADORA_H
#define CALCULADORA_H

// Classe para calcular a menor distancia entre
// duas células em uma MyMatrix
class Calculadora {
public:
    static double getDistancia(const int &linha1,
                                const int &coluna1,
                                const int &linha2,
                                const int &coluna2);
    static void testarCalculadora();
};



#endif //CALCULADORA_H
