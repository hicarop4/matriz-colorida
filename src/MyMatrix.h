//
// Created by Eu on 10/07/2024.
//

#ifndef MYMATRIX_H
#define MYMATRIX_H

#include "Pixel.h"

using namespace std;

template<typename T>
class MyMatrix {
public:
    MyMatrix(const string& _tipoDeArquivo, int _qtdColunas, int _qtdLinhas, int _limiteCor);
    ~MyMatrix();

    const Pixel ** getData() const;
    const string& getTipoDeArquivo() const;
    int getQtdColunas() const;
    int getQtdLinhas() const;
    int getLimiteCor() const;
    void imprimir() const;
    void lerEntrada() const;

private:
    // Matriz principal para ler os pixels da imagem
    Pixel **data;

    // (tipo do arquivo PPM: P3, P6, etc...
    const string& tipoDeArquivo;
    int qtdColunas{};
    int qtdLinhas{};
    int limiteCor;

};


template<typename T>
MyMatrix<T>::MyMatrix(const string& _tipoDeArquivo, int _qtdColunas, int _qtdLinhas, int _limiteCor)
    :
          tipoDeArquivo(_tipoDeArquivo),
          qtdColunas(_qtdColunas),
          qtdLinhas(_qtdLinhas), limiteCor(_limiteCor)
{

    this->data = new Pixel*[qtdLinhas];
    for (int i = 0; i < qtdLinhas; i++) {
        this->data[i] = new Pixel[qtdColunas];
    }
}

template<typename T>
void MyMatrix<T>::lerEntrada() const {
    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            // Le o valor de cada pixel (cada pixel possui 3 cores, indo de 0 até 255)
            this->data[i][j].ler();
        }
    }
}

template<typename T>
void MyMatrix<T>::imprimir() const {
    cout << this->getTipoDeArquivo() << "\n";
    cout << this->getQtdColunas() << " ";
    cout << this->getQtdLinhas() << "\n";
    cout << this->getLimiteCor() << "\n";

    for (int i = 0; i < this->getQtdLinhas(); i++) {
        for (int j = 0; j < this->getQtdColunas(); j++) {
            this->data[i][j].imprimir();
        }
        cout << "\n";
    }
}

template<typename T>
const Pixel ** MyMatrix<T>::getData() const {
    return this->data;
}

template<typename T>
const string& MyMatrix<T>::getTipoDeArquivo() const{
    return this->tipoDeArquivo;
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
int MyMatrix<T>::getLimiteCor() const {
    return this->limiteCor;
}

template<typename T>
MyMatrix<T>::~MyMatrix() {
    for (int i = 0; i < qtdLinhas; i++) {
        delete[] data[i];
    }
    delete[] data;
}



#endif //MYMATRIX_H
