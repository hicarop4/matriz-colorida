//
// Created by Eu on 10/07/2024.
//

#ifndef PIXEL_H
#define PIXEL_H



class Pixel {
private:
    int cores[3];
public:
    Pixel();
    Pixel(const int *_cores);
    ~Pixel();

    void imprimir();
    void ler();
};



#endif //PIXEL_H
