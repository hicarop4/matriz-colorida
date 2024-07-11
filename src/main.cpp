#include <iostream>

#include "MyMatrix.h"

using namespace std;

int main(int argv, const char **argc) {
    string tipoDeArquivo;
    int qtdLinhas, qtdColunas, limiteCor;
    cin >> tipoDeArquivo;
    cin >> qtdColunas >> qtdLinhas >> limiteCor;

    const MyMatrix<int> *matrix = new MyMatrix<int>(tipoDeArquivo, qtdColunas,
                                                    qtdLinhas, limiteCor);
    matrix->lerEntrada();
    matrix->imprimir();
    return 0;

}
