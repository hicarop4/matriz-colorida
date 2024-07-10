#include <iostream>

#include "MyMatrix.h"
#include "Input.h"

using namespace std;

int main(int argv, const char **argc) {
    string qtdPontosPretos;
    int qtdLinha, qtdColunas, limiteCor;
    cin >> qtdPontosPretos;
    cin >> qtdLinha >> qtdColunas >> limiteCor;

    const MyMatrix<int> *matrix = new MyMatrix<int>(Input::sanitizeInputPontosPretos(qtdPontosPretos), qtdColunas, qtdLinha, limiteCor);
    cout << matrix->getQtdPontosPretos();


    delete matrix;
}
