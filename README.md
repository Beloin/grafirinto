# :globe_with_meridians: Grafirinto

Implementação de um _minigame_ de labirinto no qual o jogador percorre os vértices de uma **estrutura de dados grafo**.

## :compass: O labirinto

Inicialmente, o grafo possui uma quantidade par de vértices.

Com a primeira metade é formada a **rota principal**, ligando de forma sequêncial o início e o fim do labirinto, esses serão os **vértices principais**.

Com a metade restante, os **vértices distratores**, são formadas **rotas alternativas**, pois de forma aleatória para cada **vértice distrator** será formado **3** arestas entre ele e outros vértices sorteados do grafo, podendo resultar numa rota mais longa ou mais curta.

## :desktop_computer: Interface

Em execução, a partir do vértice de início, em _loop_:

1. É exibido no console se o jogador está no vértice final, e caso seja verdadeiro, é fim de jogo;
2. É exibido no console as arestas que o vértice atual possui e o jogador é questionado sobre qual opção deseja tomar;
3. O jogador informa para qual vértice deseja ir ou se prefere desistir da partida;
4. Com o destino escolhido, o vértice atual muda e o _loop_ se repete.

## :gear: Implementação

Um grafo é uma estrutura que contém todos os vértices.

```C
struct graph
{
  struct vertex *vertexArr;
  unsigned vertexArrLength;
};
```

Onde cada vértice contém um valor para identificação e suas arestas, nesse caso, ponteiros para outros vértices.

```C
struct vertex
{
  struct vertex **vertexArr;
  unsigned vertexArrLength;
  char *valueID;
};
```

## :octocat: Autores

|                        Aluno                         |
| :--------------------------------------------------: |
| [![newtmagalhaes]](https://github.com/newtmagalhaes) |
|        [![Beloin]](https://github.com/Beloin)        |

<!-- Links para imagens de perfil -->

[newtmagalhaes]: https://avatars.githubusercontent.com/newtmagalhaes?size=100
[beloin]: https://avatars.githubusercontent.com/Beloin?size=100
