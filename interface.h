#pragma once

#include "graph.h"

// Exibe no console as arestas de um vértice e retorna essa quantidade
unsigned printEdges(Vertex *vertice)
{
  return vertice->edgeArrLength;
}

void printVertex(Vertex *vertice)
{
  printf("Vertex: %d\n", vertice->valueID);
}

/* 
 *  Com base na quantidade de opções verifica se
 * o usuário escolheu uma opção válida e a retorna 
*/
unsigned getOption(unsigned numberOfOptions)
{
}

void app()
{
  // printf Tela de Apresentação.

  // Escolha de dificuldade getOption();
  // criar Grafo de acordo com a dificuldade.
  Graph *graph = createGraph(getOption(10));

  // Vertice atual.
  Vertex *currentVertex = graph->vertexArr[0];

  // Opção da escolha dos vértices.
  unsigned option = 0;

  // Verifica se o usuário ganhou, ou desistiu.
  unsigned desistencia = 0;

  // main loop => Enquanto não estiver na saída.
  while (!currentVertex->isExit)
  {
    // Print vertice atual: printVertex();
    printVertex(currentVertex);

    // Opcional: Print [MAPA]

    // printEdges() mostra os vértices para ir a partir do atual.
    // getOption(); // incluir opção desistência
    option = getOption(1 + printEdges(currentVertex));
    if (option > currentVertex->edgeArrLength)
    {
      desistencia = 1;
      break;
    }

    // ir para vértice escolhido
    currentVertex = currentVertex->edgeArr[option];
  }

  if (!desistencia)
  {
    // se SAÍDA: Parabéns você venceu!
    printf("Ganhou!\n");
  }
  else
  {
    // se DESISTIR: Ah, que pena!
    printf("Ah que pena! Você abandonou a partida!\n");
  }
}