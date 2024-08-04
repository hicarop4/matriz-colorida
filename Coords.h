//
// Created by Hícaro on 03/08/2024.
//

#ifndef COORDS_H
#define COORDS_H

class Coords {
public:
    Coords(int _linha, int _coluna) : linha(_linha), coluna(_coluna) {};
    Coords() : linha(0), coluna(0) {};
    int linha;
    int coluna;

    bool operator< (const Coords &other) const {
        if(this->linha < other.linha) {
            return true;
        }
        if(this->linha > other.linha) {
            return false;
        }
        // nesse caso sabemos que as linhas sao iguais
        // entao desempatamos pela coluna
        if(this->coluna < other.coluna) {
            return true;
        }
        return false;
    }
};

#endif //COORDS_H
