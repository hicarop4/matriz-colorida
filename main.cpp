#include <iostream>
#include <cstring>

#include "includes/MyMatrix.h"
#include "includes/Pixel.h"
#include "includes/Calculadora.h"
#include "includes/GeradorImagem.h"
#include "includes/Impressora.h"


using namespace std;

int main(int argc, const char **argv) {
    if (argc < 3) {
        std::cerr << "Uso correto: " << argv[0] << " <ALGORITMO> <MODO_SAIDA> < <entrada.pbm> > <saida.pbm>" << std::endl;
        std::cerr << "Opções de ALGORITMO: trivial, melhorado, eficiente" << std::endl;
        std::cerr << "Opções de MODO_SAIDA: distancia, resumo, imagem" << std::endl;
        return 1; // retorna erro
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

    // cria uma matrix de pixel;
    MyMatrix<Pixel> *matrix = new MyMatrix<Pixel>(qtdColunas,
                                                    qtdLinhas);
    matrix->lerEntrada();


    // *********** PARTE MAIS IMPORTANTE DO PROJETO ***********
    // gera a matriz de distancias baseado no algoritmo escolhido
    MyMatrix<double> *distancias;
    if(strcmp(algoritmo, "trivial") == 0) {
        distancias = Calculadora::gerarDistanciasTrivial(matrix);
    } else if(strcmp(algoritmo, "melhorado") == 0) {
        distancias = Calculadora::gerarDistanciasTrivialMelhorado(matrix);
    } else {
        distancias = Calculadora::gerarDistanciasEficiente(matrix);
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
