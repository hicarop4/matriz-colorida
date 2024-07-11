//
// Created by Eu on 10/07/2024.
//

#include "Pixel.h"
#include <iostream>

Pixel::Pixel() {
    for (int i = 0; i < 3; i++) {
        cores[i] = 0;
    }
}

Pixel::Pixel(const int *_cores) {
    for (int i = 0; i < 3; i++) {
        cores[i] = _cores[i];
    }
}

void Pixel::ler() {
    for (int i = 0; i < 3; i++) {
        std::cin >> this->cores[i];
    }
}

void Pixel::imprimir() {
    for (int i = 0; i < 3; i++) {
        std::cout << cores[i] << " ";
    }
}

Pixel::~Pixel() {
    delete[] cores;
}


