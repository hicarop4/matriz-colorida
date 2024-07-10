//
// Created by Eu on 10/07/2024.
//

#ifndef MYMATRIX_H
#define MYMATRIX_H
#include <string>

using namespace std;

template<typename T>
class MyMatrix {
public:
    MyMatrix(int _qtdPontosPretos, int _qtdColunas, int _qtdLinhas, int _limiteCor);
    ~MyMatrix();

    const T ** getData() const;
    int getQtdPontosPretos() const;
    int getQtdColunas() const;
    int getQtdLinhas() const;


private:
    // Matriz principal para ler os pixeis da imagem
    T **data;

    int qtdPontosPretos{};
    int qtdColunas{};
    int qtdLinhas{};
    int limiteCor;

};

template<typename T>
MyMatrix<T>::MyMatrix(int _qtdPontosPretos, int _qtdColunas, int _qtdLinhas, int _limiteCor)
    :
          qtdPontosPretos(_qtdPontosPretos),
          qtdColunas(_qtdColunas),
          qtdLinhas(_qtdLinhas), limiteCor(_limiteCor)
{

    this->data = new T*[qtdLinhas];
    for (int i = 0; i < qtdLinhas; i++) {
        this->data[i] = new T[qtdColunas];
    }
}

template<typename T>
MyMatrix<T>::~MyMatrix() {
    for (int i = 0; i < qtdLinhas; i++) {
        delete[] data[i];
    }
    delete[] data;
}

template<typename T>
const T ** MyMatrix<T>::getData() const {
    return this->data;
}

template<typename T>
int MyMatrix<T>::getQtdPontosPretos() const {
    return this->qtdPontosPretos;
}

template<typename T>
int MyMatrix<T>::getQtdColunas() const {
    return this->qtdColunas;
}

template<typename T>
int MyMatrix<T>::getQtdLinhas() const {
    return this->getQtdLinhas();
}

#endif //MYMATRIX_H
