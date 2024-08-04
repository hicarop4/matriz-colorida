//
// Created by Hícaro on 13/07/2024.
//

#include "Calculadora.h"

#include <cassert>
#include <cmath>
#include <iostream>

// include para a fila de prioridades usada no algoritmo eficiente
#include "MyPriorityQueue.h"
// include para uma struct de coordenadas(linha, coluna) auxiliar para manter o codigo organizado
#include "Coords.h"


// calcula a menor distancia de um determinado ponto em uma MyMatrix
// usando o algoritmo trivial(o mais ineficiente de todos)
double Calculadora::getMenorDistanciaTrivial(int linha, int coluna, const MyMatrix<Pixel> *matrix){
    double menorDistancia = std::numeric_limits<double>::max();
    // procura a menor distancia entre o pixel atual e os pixels pretos da matriz
    for (int i = 0; i < matrix->getQtdLinhas(); i++) {
        for (int j = 0; j < matrix->getQtdColunas(); j++) {
            bool ehPreto = matrix->at(i, j).ehPreto();
            if(ehPreto) {
                // se for preto, vai calcular a distancia e certificar se ela
                // é a menor distancia percorrida até o momento
                menorDistancia = std::min(getDistancia(linha, coluna, i, j), menorDistancia);
            }
        }
    }
    return menorDistancia;
}

// faz o mesmo que a função acima, mas a abordagem é ligeiramente diferente:
// ESTA função percorre apenas os pontos pretos de uma MyMatrix
 double Calculadora::getMenorDistanciaTrivialMelhorado(int linha, int coluna,
                                                        const MyVec<std::pair<int, int>> &coords)
{
     double menorDistancia = std::numeric_limits<double>::max();
     for(int i = 0; i < coords.size(); i++) {
         // certifica qual a menor distância percorrida até agora
         menorDistancia = std::min(getDistancia(linha, coluna, coords[i].first, coords[i].second), menorDistancia);
     }
     return menorDistancia;
}

// gera uma nova MyMatrix "distancias" onde cada elemento é a distancia
// do respectivo ponto na matrix de entrada até o ponto preto mais proximo dessa matrix.
MyMatrix<double> * Calculadora::gerarDistanciasTrivial(const MyMatrix<Pixel> *matrix) {
    MyMatrix<double> *distancias = new MyMatrix<double>(matrix->getQtdColunas(), matrix->getQtdLinhas());
    // encontra o pixel preto mais próximo para cada pixel usando algoritmo mais intuitivo
    // e com complexidade O(n^4)
    for (int i = 0; i < distancias->getQtdLinhas(); i++) {
        for (int j = 0; j < distancias->getQtdColunas(); j++) {
             distancias->at(i,j) = getMenorDistanciaTrivial(i,j,matrix);
        }
    }
    return distancias;
}

MyMatrix<double> * Calculadora::gerarDistanciasTrivialMelhorado(const MyMatrix<Pixel> *matrix) {
    MyVec<std::pair<int, int>> coords;
    contarPontosPretos(matrix, coords);
    MyMatrix<double> *distancias = new MyMatrix<double>(matrix->getQtdColunas(), matrix->getQtdLinhas());
    // encontra o pixel preto mais próximo para cada pixel usando algoritmo
    // com complexidade O(n^3)
    for (int i = 0; i < matrix->getQtdLinhas(); i++) {
        for (int j = 0; j < matrix->getQtdColunas(); j++) {
            distancias->at(i, j) = getMenorDistanciaTrivialMelhorado(i, j, coords);
        }
    }
    return distancias;
}

MyMatrix<double> * Calculadora::gerarDistanciasEficiente(const MyMatrix<Pixel> *matrix) {
    MyPriorityQueue<std::pair<double, Coords>> queue;

    MyMatrix<double> *distancias = new MyMatrix<double>(matrix->getQtdColunas(), matrix->getQtdLinhas());
    MyMatrix<bool> *distanciaFoiProcessada = new MyMatrix<bool>(matrix->getQtdColunas(), matrix->getQtdLinhas());

    // inicia a matriz resultante distancias com distancia infinita
    // E adiciona os pontos pretos na fila de prioridades
    double infinito = std::numeric_limits<double>::max();
    for (int i = 0; i < matrix->getQtdLinhas(); i++) {
        for (int j = 0; j < matrix->getQtdColunas(); j++) {
            distancias->at(i, j) = infinito;
            distanciaFoiProcessada->at(i, j) = false;
            if (matrix->at(i,j).ehPreto()) {
                distancias->at(i, j) = 0;
                Coords posicao(i, j);
                queue.push(std::make_pair(0.0, posicao));
            }
        }
    }

    // atualiza as células das distancias
    while(queue.size() != 0) {
        std::pair<double, Coords> elem = queue.top();
        queue.pop();
        int linha = elem.second.linha;
        int coluna = elem.second.coluna;
        // se a distancia foi processada podemos ignorar esta iteração
        if(distanciaFoiProcessada->at(linha, coluna)) continue;
        // marca a celula como processada na matriz de distancias
        distanciaFoiProcessada->at(linha, coluna) = true;

        // atualiza cada vizinho
        MyVec<Coords> *vizinhos = obterVizinhos(linha, coluna, matrix->getQtdLinhas(), matrix->getQtdColunas());
        for (int i = 0; i < vizinhos->size(); i++) {
            // atualiza a distancia entre cada vizinho e o elemento de menor prioridade
            int linhaVizinho = (*vizinhos)[i].linha;
            int colunaVizinho = (*vizinhos)[i].coluna;
            double distanciaAtual = distancias->at(linha, coluna);
            double distanciaVizinho = distancias->at(linhaVizinho, colunaVizinho);
            double distanciaAteOVizinho = getDistanciaVizinho(linha, coluna, linhaVizinho, colunaVizinho);
            // se a nova distancia encontrada for menor que a distancia que temos armazenada no vizinho
            if((distanciaAtual + distanciaAteOVizinho) < distanciaVizinho) {
                // atualiza a distancia do vizinho com a nova distancia
                distancias->at(linhaVizinho, colunaVizinho) = (distanciaAtual + distanciaAteOVizinho);
                Coords posicaoVizinho = Coords(linhaVizinho, colunaVizinho);
                queue.push(std::make_pair(-(distanciaAtual + distanciaAteOVizinho), posicaoVizinho));
            }
        }
        delete vizinhos;
    }

    delete distanciaFoiProcessada;
    return distancias;
}


// calcula a distancia de um elemento para outro em determinada matriz
// *utilizado nos algoritmos triviais*
double Calculadora::getDistancia(const int &linha1,
                                 const int &coluna1,
                                 const int &linha2,
                                 const int &coluna2) {
    int a = abs(linha2 - linha1);
    int b = abs(coluna2 - coluna1);
    return sqrt(pow(a, 2) + pow(b, 2));
}


// conta a quantidade de pontos pretos em uma MyMatrix e armazena
// em um MyVec cada par <linha, coluna>
void Calculadora::contarPontosPretos(const MyMatrix<Pixel> *matrix, MyVec<std::pair<int, int>> &coords) {
    for (int i = 0; i < matrix->getQtdLinhas(); i++) {
        for (int j = 0; j < matrix->getQtdColunas(); j++) {
            if (matrix->at(i,j).ehPreto())
                coords.push_back(std::make_pair(i, j));
        }
    }
}


double Calculadora::getDistanciaVizinho(const int &linha1, const int &coluna1, const int &linha2, const int &coluna2) {
    int deltaLinha = std::abs(linha1 - linha2);
    int deltaColuna = std::abs(coluna1 - coluna2);

    if (deltaLinha == 1 && deltaColuna == 1) {
        // Distância diagonal
        return 1.4;
    } else if ((deltaLinha == 1 && deltaColuna == 0) || (deltaLinha == 0 && deltaColuna == 1)) {
        // Distância horizontal ou vertical
        return 1.0;
    } else {
        // Caso especial: se os elementos forem iguais, a distância é zero
        // ou pode ser que não sejam vizinhos adjacentes.
        return 0.0;
    }
}

MyVec<Coords> *Calculadora::obterVizinhos(int linha, int coluna, int maxLinhas, int maxColunas) {
    MyVec<Coords> *vizinhos = new MyVec<Coords>;

    // Coordenadas relativas dos 8 vizinhos (incluindo diagonais)
    int direcao[8][2] = {{-1,-1}, {-1,0}, {-1,1},{0, -1}, {0, 1}, {1, -1}, {1,0}, {1,1} };

    for (int i = 0; i < 8; ++i) {
        int novaLinha = linha + direcao[i][0];
        int novaColuna = coluna + direcao[i][1];

        // Verifica se as novas coordenadas estão dentro dos limites da matriz
        if (novaLinha >= 0 && novaLinha < maxLinhas && novaColuna >= 0 && novaColuna < maxColunas) {
            vizinhos->push_back({novaLinha, novaColuna});
        }
    }

    return vizinhos;
}

void Calculadora::testarCalculadora() {
    assert(Calculadora::getDistancia(0, 0, 1, 1) == sqrt(2));
    std::cout << "Teste 1 passou!\n";
}
