//
// Created by Eu on 10/07/2024.
//

#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <iostream>   // Para std::cin, std::cout, std::endl
#include <cmath>      // Para funções matemáticas como std::round
#include <stdexcept>  // Para std::out_of_range

using namespace std;

template<typename T>
class MyMatrix {
public:
    T ** getData() const;

    // construtores e destrutores
    MyMatrix(int _qtdColunas, int _qtdLinhas);
    ~MyMatrix();

    // métodos de acesso
    T& at(long long linha, long long coluna);
    const T& at(long long linha, long long coluna) const; //read-only

    void lerEntrada() const;

    void imprimir() const;

    int getQtdColunas() const;
    int getQtdLinhas() const;

private:
    // guarda os dados da matriz principal
    T **data;

    int qtdColunas;
    int qtdLinhas;

};


template<typename T>
MyMatrix<T>::MyMatrix(int _qtdColunas, int _qtdLinhas)
    :
          qtdColunas(_qtdColunas),
          qtdLinhas(_qtdLinhas)
{
    // cria a matriz 2d principal
    this->data = new T*[_qtdLinhas];
    for (int i = 0; i < _qtdLinhas; i++) {
        this->data[i] = new T[_qtdColunas];
    }
}

template<typename T>
void MyMatrix<T>::lerEntrada() const {
    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            std::cin >> this->data[i][j];
        }
    }
}

template<typename T>
void MyMatrix<T>::imprimir() const {
    for (int i = 0; i < this->qtdLinhas; i++) {
        for (int j = 0; j < this->qtdColunas; j++) {
            cout << this->data[i][j] << " ";
        }
        cout << "\n";
    }
}

template<typename T>
T ** MyMatrix<T>::getData() const {
    return this->data;
}

template<typename T>
int MyMatrix<T>::getQtdColunas() const {
    return this->qtdColunas;
}

template<typename T>
int MyMatrix<T>::getQtdLinhas() const {
    return this->qtdLinhas;
}

template<typename T>
MyMatrix<T>::~MyMatrix() {
    for (int i = 0; i < qtdLinhas; i++) {
        delete[] data[i];
    }
    delete[] data;

}

template<typename T>
T & MyMatrix<T>::at(long long linha, long long coluna) {
    if (linha < 0 || linha >= qtdLinhas || coluna < 0 || coluna >= qtdColunas) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[linha][coluna];
}

template<typename T>
const T & MyMatrix<T>::at(long long linha, long long coluna) const {
    if (linha < 0 || linha >= qtdLinhas || coluna < 0 || coluna >= qtdColunas) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[linha][coluna];
}

#endif //MYMATRIX_H
