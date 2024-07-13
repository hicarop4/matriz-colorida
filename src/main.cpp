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

    const MyMatrix<Pixel> *matrix = new MyMatrix<Pixel>(qtdColunas,
                                                    qtdLinhas);
    cout << tipoDeArquivo << "\n";
    cout << qtdColunas << " " << qtdLinhas << "\n";
    cout << 255 << "\n";
    matrix->imprimirDistancias();
    return 0;

}
