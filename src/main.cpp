#include <iostream>

#include "Impressora.h"
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
    matrix->lerEntrada();

    // cout << tipoDeArquivo << "\n";
    // cout << qtdColunas << " " << qtdLinhas << "\n";
    // cout << 255 << "\n";
    auto distancias = Calculadora::gerarDistanciasTrivialMelhorado(matrix);
    Impressora::imprimirResumo(distancias);
    delete matrix;
    delete distancias;
    return 0;
}
