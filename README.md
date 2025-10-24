# Coloração Automática de Imagens em P&B
## Transforme suas imagens em preto e branco em obras vibrantes de forma mágica! ✨
### Este programa em C++ pega uma simples imagem em formato PPM preto e branco e cria uma nova versão cheia de cores, baseada em cálculos matemáticos que garantem uma explosão de tons únicos. 
------------------------------------------------------------------

<div style="display: flex;">
    <img src="https://github.com/user-attachments/assets/b811c676-2933-40cd-94b8-1d22ec7004c9" alt="antesCavalo" width="300" height="300" style="margin-right: 30px;"/>
    <img src="https://github.com/user-attachments/assets/5eebc267-9aa9-4e38-bfda-1d5b5723673b" alt="depoisCavalo" width="300" height="300"/>
</div>


<div style="display: flex;">
    <img src="https://github.com/user-attachments/assets/4ae23ae6-ce0d-4bd4-bcd2-956f45c68cbe" alt="antes" width="300" height="300" style="margin-right: 30px;"/>
    <img src="https://github.com/user-attachments/assets/d320b220-544a-43e1-90cf-b470ee51a81b" alt="depois" width="300" height="300"/>
</div>


------------------------------------------------------------------

Você pode escolher três algoritmos, escolha-os baseado na quantidade de linhas, colunas e pontos pretos da sua imagem.
A complexidade de cada algoritmo:

1) Algoritmo trivial
- Complexidade: **O(L^2 * C^2)**
- Justificativa sucinta: A função desse algoritmo percorre todos os pixels da matriz O(L * C) e para cada pixel ela chama a função getMenorDistanciaTrivial que
também percorre todos os pixels da matriz para encontrar a menor distância até um pixel preto O(L * C)

2) Algoritmo melhorado
- Complexidade: **O(L * C * P)**
- Justificativa sucinta: A função desse algoritmo percorre todos os pixels da matriz O(L * C) e para cada pixel chama "getMenorDistanciaTrivialMelhorado"
que percorre um MyVec de coordenadas de pontos pretos O(P)

3) Algoritmo eficiente
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


## Compilação e Execução
Antes de compilar e executar o programa, você precisará ter o seguinte instalado:

- [CMake](https://cmake.org/download/) (versão 3.22.1 ou superior)
- [GNU Compiler Collection (GCC)](https://gcc.gnu.org/) (ou um compilador C++ compatível)
- [CLion](https://www.jetbrains.com/clion/) (opcional, mas recomendado para facilitar o desenvolvimento)


<br> Para compilar e executar o programa, utilize os seguintes comandos no terminal:<br/>

```bash
# Crie um diretório de build e navegue até ele
mkdir build && cd build

# Execute o CMake para gerar os arquivos de compilação
cmake ..

# Compile o projeto
cmake --build .

# Execute o programa
./COLORIR  # Ou execute pelo CLion
```

- Créditos do header HSV2RGB: Salles Magalhães

