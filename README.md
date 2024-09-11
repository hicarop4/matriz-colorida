Eu li as regras
# Matriz de Distância
## Programa feito em C++ para calcular a distância entre cada pixel preto em uma imagem
------------------------------------------------------------------
A complexidade de cada algoritmo:

1) Algoritmo trivial
- Complexidade: **O(L^2 * C^2)**
- Justificativa sucinta: A função desse algoritmo percorre todos os pixels da matriz O(L * C) e para cada pixel ela chama a função getMenorDistanciaTrivial que
também percorre todos os pixels da matriz para encontrar a menor distância até um pixel preto O(L * C)

2) Algoritmo melhorado
- Complexidade: **O(L * C * P)**
- Justificativa sucinta: A função desse algoritmo percorre todos os pixels da matriz O(L * C) e para cada pixel chama "getMenorDistanciaTrivialMelhorado"
que percorre um MyVec de coordenadas de pontos pretos O(P)

3) Algoritmo eficiente (parte 2 do trabalho)
- Complexidade: **O(L * C * log(L * C))**
- Justificativa sucinta: A função usa uma fila de prioridades QUEUE para implementar uma espécie de algoritmo de propagação de ondas.
O algoritmo usa uma fila de prioridade para processar as células da matriz, onde cada inserção e remoção possui complexidade O(log(L*C)),
como todos pixels são processados O(L * C), a complexidade final é o produto dos dois.

Casos de teste e seus tempos na prática:

| Tamanho  | Descrição                              | Tempo trivial (s) | Tempo melhorado (s) | Tempo eficiente (s) |
|----------|----------------------------------------|-------------------|---------------------|---------------------|
| 10x12    | Imagem com quadrados pequenos           | 0.2s              | 0.3~                | 0.31~               |
| 50x50    | Imagem com um triângulo bem grande      | 1.40~             | 1.13~               | 1.02~               |
| 100x100  | Imagem com o máximo de triângulos       | ----              | 8.00~               | 2.1~                |
| 1000x1000| Imagem com triângulos nas bordas        | ------            | -----               | 21s~                |


Conforme esperado, O algoritmo trivial se torna rapidamente impraticável em 
matrizes maiores e com maior complexidade, como pode ser observado nos casos de 100x100 e 
1000x1000, onde o tempo de execução foi tão elevado que a função não completou dentro de um período razoável.

O algoritmo melhorado, por outro lado mostrou uma performance melhor em comparação com o trivial, especialmente em casos de tamanhos menores e moderados, como a matriz 50x50, onde ele conseguiu ser mais rápido que o trivial. No entanto, em casos de maior complexidade como o de 100x100 com muitos triângulos, ele ainda sofre devido a sua complexidade
O(L×C×P), tornando-se menos eficiente em matrizes muito grandes ou com muitos pixels pretos.

Por fim, o algoritmo eficiente, se destaca, especialmente em matrizes maiores e mais complexas, como na de 100x100 com o máximo de triângulos e na de 1000x1000 com triângulos nas bordas. Mesmo em cenários onde os outros algoritmos falharam ou foram muito lentos, o algoritmo eficiente manteve tempos razoáveis, graças à sua complexidade,
o que o torna escalável e adequado para imagens grandes e complexas.


