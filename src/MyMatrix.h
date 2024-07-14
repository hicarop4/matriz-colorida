//
// Created by Eu on 10/07/2024.
//

#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <cmath>

using namespace std;

template<typename T>
class MyMatrix {
public:
    T ** getData() const;
    double ** getDistancias() const;

    // construtores e destrutores
    MyMatrix(int _qtdColunas, int _qtdLinhas);
    ~MyMatrix();

    // métodos de acesso
    T& at(long long linha, long long coluna);
    const T& at(long long linha, long long coluna) const; //read-only

    void lerEntrada() const;

    void imprimir() const;
    void imprimirDistancias() const;
    void imprimirResumo() const;

    int getQtdColunas() const;
    int getQtdLinhas() const;

private:
    // guarda os dados da matriz principal
    T **data;
    // guarda as distancias entre cada célula da matriz principal "data"
    double **distancias;

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

    // cria outra matriz 2d com o mesmo tamanho de linhas e colunas
    this->distancias = new double*[_qtdLinhas];
    for (int i = 0; i < _qtdLinhas; i++)
        this->distancias[i] = new double[_qtdColunas];

    // le os valores da matriz principal
    this->lerEntrada();
}

template<typename T>
void MyMatrix<T>::lerEntrada() const {
    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            // Le o valor de cada pixel (cada pixel possui 3 cores, indo de 0 até 255)
            std::cin >> this->data[i][j];
        }
    }
}

template<typename T>
void MyMatrix<T>::imprimir() const {
    for (int i = 0; i < this->getQtdLinhas(); i++) {
        for (int j = 0; j < this->getQtdColunas(); j++) {
            cout << this->data[i][j] << " ";
        }
        cout << "\n";
    }
}

template<typename T>
void MyMatrix<T>::imprimirDistancias() const {
    for (int i = 0; i < this->getQtdLinhas(); i++) {
        for (int j = 0; j < this->getQtdColunas(); j++) {
            cout << std::round(this->distancias[i][j]) << " ";
        }
        cout << "\n";
    }
}

template<typename T>
void MyMatrix<T>::imprimirResumo() const {

    unsigned long long soma = 0;
    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            soma += std::round(distancias[i][j]);
        }
    }
    cout << soma << endl;
}


template<typename T>
T ** MyMatrix<T>::getData() const {
    return this->data;
}

template<typename T>
double ** MyMatrix<T>::getDistancias() const {
    return this->distancias;
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
        delete[] distancias[i];
    }
    delete[] data;
    delete[] distancias;

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
