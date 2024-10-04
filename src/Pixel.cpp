//
// Created by Eu on 10/07/2024.
//

#include "../includes/Pixel.h"

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

Pixel::Pixel(const int r, const int g, const int b) {
    cores[0] = r;
    cores[1] = g;
    cores[2] = b;
}

void Pixel::ler() {
    for (int i = 0; i < 3; i++) {
        std::cin >> this->cores[i];
    }
}

void Pixel::imprimir() {
    std::cout << (*this);
}

bool Pixel::ehPreto() const {
    return !(this->cores[0] && this->cores[1] && this->cores[2]);
}


std::ostream &operator<<(std::ostream &out, const Pixel &pixel) {
    out << pixel.cores[0] << " " << pixel.cores[1] << " " << pixel.cores[2];
    return out;
}

std::istream &operator>>(std::istream &in, Pixel &pixel) {
    in >> pixel.cores[0] >> pixel.cores[1] >> pixel.cores[2];
    return in;
}