#include <iostream>
#include <cstring>

#include "MyMatrix.h"
#include "Pixel.h"
#include "Calculadora.h"
#include "GeradorImagem.h"
#include "Impressora.h"


using namespace std;

int main(int argc, const char **argv) {
    if (argc < 3) {
        std::cerr << "Uso correto: " << argv[0] << " <ALGORITMO> <MODO_SAIDA> < <entrada.pbm> > <saida.pbm>" << std::endl;
        return 1; // Retorna erro
    }

    // le os argumentos
    char algoritmo[50];
    char modoSaida[50];
    strcpy(algoritmo, argv[1]);
    strcpy(modoSaida, argv[2]);

    // le as informações sobre a imagem
    string tipoDeArquivo;
    int qtdLinhas, qtdColunas, limiteCor;
    cin >> tipoDeArquivo;
    cin >> qtdColunas >> qtdLinhas >> limiteCor;

    // cria uma matrix de pixel e calcula as distancias entre cada pixel;
    MyMatrix<Pixel> *matrix = new MyMatrix<Pixel>(qtdColunas,
                                                    qtdLinhas);
    matrix->lerEntrada();


    // gera distancias baseado no algoritmo
    MyMatrix<double> *distancias;
    if(strcmp(algoritmo, "trivial") == 0) {
        distancias = Calculadora::gerarDistanciasTrivial(matrix);
    } else if(strcmp(algoritmo, "melhorado") == 0) {
        distancias = Calculadora::gerarDistanciasTrivialMelhorado(matrix);
    } else {
        // TODO
        distancias = NULL;
    }

    // define o que será a saída do programa
    if(strcmp(modoSaida, "distancia") == 0) {
        Impressora::imprimirDistancias(distancias);
    } else if(strcmp(modoSaida, "resumo") == 0) {
        Impressora::imprimirResumo(distancias);
    } else {
        MyMatrix<Pixel> *imagem = GeradorImagem::gerarImagem(distancias);
        Impressora::imprimirImagem(tipoDeArquivo, imagem);
        delete imagem;
    }

    // evitar vazamento de memoria!
    delete matrix;
    delete distancias;
    return 0;
}
