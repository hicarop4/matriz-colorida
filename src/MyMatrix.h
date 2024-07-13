//
// Created by Eu on 10/07/2024.
//

#ifndef MYMATRIX_H
#define MYMATRIX_H

#include "Calculadora.h"
#include "CalculaMenorDistanciaPixelPreto.h"

using namespace std;

template<typename T>
class MyMatrix {
public:
    const T ** getData() const;

    // construtores e destrutores
    MyMatrix(int _qtdColunas, int _qtdLinhas);
    ~MyMatrix();

    // métodos de acesso
    T& get(long long linha, long long coluna){return data[linha][coluna];}
    const T& get(long long linha, long long coluna) const {return data[linha][coluna];} //read-only

    void gerarDistancias();
    void imprimirDistancias() const;

    int getQtdColunas() const;
    int getQtdLinhas() const;
    void imprimir() const;
    void lerEntrada() const;

private:
    // guarda os dados da matriz principal
    T **data;
    // guarda as distancias entre cada célula da matriz principal "data"
    double **distancia;

    int qtdColunas;
    int qtdLinhas;

};


template<typename T>
MyMatrix<T>::MyMatrix(int _qtdColunas, int _qtdLinhas)
    :
          qtdColunas(_qtdColunas),
          qtdLinhas(_qtdLinhas)
{

    this->data = new T*[qtdLinhas];
    for (int i = 0; i < qtdLinhas; i++) {
        this->data[i] = new T[qtdColunas];
    }

    this->lerEntrada();
    this->gerarDistancias();
}

template<typename T>
void MyMatrix<T>::gerarDistancias() {
    // cria uma matriz 2d com o mesmo tamanho de linhas e colunas
    // que a matriz principal
    this->distancia = new double*[qtdLinhas];
    for (int i = 0; i < qtdLinhas; i++)
        this->distancia[i] = new double[qtdColunas];

    // encontra o pixel preto mais próximo para cada pixel
    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            this->distancia[i][j] = CalculaMenorDistanciaPixelPreto::getMenorDistancia(
                                                            qtdLinhas,
                                                            qtdColunas,
                                                            i,
                                                            j,
                                                            this->data);
        }
    }
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
            cout << std::round(this->distancia[i][j]) << " ";
        }
        cout << "\n";
    }
}


template<typename T>
const T ** MyMatrix<T>::getData() const {
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

#endif //MYMATRIX_H
