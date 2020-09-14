# :globe_with_meridians: Grafirinto

Implementação de um _minigame_ de labirinto no qual o jogador percorre os vértices de uma **estrutura de dados grafo**.

## :compass: O labirinto

Inicialmente, o grafo possui uma quantidade de vértices múltipla de 3.

Com o primeiro terço é formado a **rota principal**, ligando de forma sequêncial o início e o fim do labirinto, esses serão os **vértices principais**.

Com os dois terços restantes, os **vértices distratores**, são formados **rotas alternativas**, pois de forma aleatória para cada **vértice distrator** haverá 50% de chance de formar arestas entre ele e cada um dos outros vértices do grafo, podendo resultar numa rota mais longa ou mais curta.

## :desktop_computer: Interface

Em execução, o programa funciona em etapas:

1. Exibe uma tela de apresentação;
2. O jogador informa a dificuldade desejada do _grafirinto_;
3. Com base na escolha é gerado um grafo com 3 vezes essa quantidade de vértices;
4. A partir do vértice de início (como sendo atual), começa o _loop_ enquanto o vértice atual não for o de saída:

   1. É exibido no console o vértice atual;
   2. É exibido no console uma matriz com as arestas existentes do grafo;
   3. É exibido no console as arestas que o vértice atual possui ou se prefere desistir;
   4. O jogador é questionado sobre qual opção deseja tomar;
   5. Caso escolha desistir, o _loop_ é quebrado e a partida acaba;
   6. Caso escolha outro vértice, o vértice atual se torna o escolhido e o _loop_ se repete enquanto a condição for verdadeira;

5. Ao sair do _loop_, o grafo é desalocado e é exibido uma mensagem para caso ele tenha desistido ou não.

## :gear: Implementação

Um grafo é uma estrutura que contém o endereço de todos os vértices.

```C
struct graph
{
  struct vertex *vertexArr;
  unsigned vertexArrLength;
};
```

Onde cada vértice contém um valor para identificação, suas arestas e se é o vértice de saída ou não, nesse caso, ponteiros para outros vértices.

```C
struct vertex
{
  struct vertex **vertexArr;
  unsigned vertexArrLength, valueID, isExit;
};
```

## :octocat: Autores

|                    @newtmagalhaes                    |                @Beloin                 |
| :--------------------------------------------------: | :------------------------------------: |
| [![newtmagalhaes]](https://github.com/newtmagalhaes) | [![Beloin]](https://github.com/Beloin) |

<!-- Links para imagens de perfil -->

[newtmagalhaes]: https://avatars.githubusercontent.com/newtmagalhaes?size=100
[beloin]: https://avatars.githubusercontent.com/Beloin?size=100
