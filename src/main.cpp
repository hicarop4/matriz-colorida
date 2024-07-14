#include <iostream>
#include "Teste.h"
#include "MyMatrix.h"
#include "Pixel.h"


using namespace std;

int main(int argv, const char **argc) {
    Teste::rodarTestes();

    string tipoDeArquivo;
    int qtdLinhas, qtdColunas, limiteCor;
    cin >> tipoDeArquivo;
    cin >> qtdColunas >> qtdLinhas >> limiteCor;

    MyMatrix<Pixel> *matrix = new MyMatrix<Pixel>(qtdColunas,
                                                    qtdLinhas);
    // int i = 0;
    // for (i = 0; i < 100; i++) {
    //     Calculadora::gerarDistanciasTrivial(matrix);
    // }
    // for (i = 0; i < 100; i++) {
    //     Calculadora::gerarDistanciasTrivialMelhorado(matrix);
    // }
    // cout << tipoDeArquivo << "\n";
    // cout << qtdColunas << " " << qtdLinhas << "\n";
    // cout << 255 << "\n";
    Calculadora::gerarDistanciasTrivial(matrix);
    matrix->imprimirResumo();

    delete matrix;
    return 0;
}
