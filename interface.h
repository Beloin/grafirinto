#pragma once

#include <stdio.h>
#include "graph.h"

//  Retorna um unsigned informado pelo usuário que esteja no intervalo [minOption, maxOption].
unsigned getOption(unsigned minOption, unsigned maxOption)
{
  unsigned option = 0;
  do
  {
    printf("Por favor, informe um natural que pertence ao intervalo [%u, %u]: ", minOption, maxOption);
    scanf("%u", &option);
  } while ((option < minOption) || (option > maxOption));

  return option;
}

/** 
 *  Exibe no console as opções que o jogador pode escolher
 * em função da quantidade de arestas que o vértice possui
 * e retorna o total de opções disponíveis.
*/
unsigned printEdges(Vertex *vertex)
{
  for (unsigned i = 0; i < vertex->edgeArrLength; i++)
  {
    printf("Option %u: vertex(%u)\n", i, vertex->edgeArr[i]->valueID);
  }
  printf("Option %u: Abandon match\n", vertex->edgeArrLength);

  return vertex->edgeArrLength;
}

// Exibe no console uma matriz binária das arestas do grafo
void printEdgeMap(Graph *graph)
{
  // Cabeçalho da matriz
  printf("\n    |");
  for (unsigned i = 0; i < graph->vertexArrLength; i++)
  {
    printf("%4u|", graph->vertexArr[i]->valueID);
  }
  printf("\n");

  // Corpo da matriz
  for (unsigned i = 0; i < graph->vertexArrLength; i++)
  {
    // Coluna
    printf("%4u|", graph->vertexArr[i]->valueID);

    // Pares da matriz
    for (unsigned j = 0; j < graph->vertexArrLength; j++)
    {
      printf("%4u|", hasEdgeBetween(graph->vertexArr[i], graph->vertexArr[j]) ? 1 : 0);
    }
    printf("\n");
  }
  printf("\n");
}

// Exibe no console uma matriz binária das arestas do grafo.
// Marcando qual aresta é a atual e qual é a saída.
void printExitMap(Graph *graph, Vertex *currentVertex)
{
  // Cabeçalho da matriz
  printf("\nEMap|");
  for (unsigned i = 0; i < graph->vertexArrLength; i++)
  {
    if (graph->vertexArr[i] == currentVertex)
    {
      printf("Here|");
    }
    else if (graph->vertexArr[i]->isExit)
    {
      printf("Exit|");
    }
    else
    {
      printf("%4u|", graph->vertexArr[i]->valueID);
    }
  }
  printf("\n");

  // Corpo da matriz
  for (unsigned i = 0; i < graph->vertexArrLength; i++)
  {
    // Coluna
    if (graph->vertexArr[i] == currentVertex)
    {
      printf("Here|");
    }
    else if (graph->vertexArr[i]->isExit)
    {
      printf("Exit|");
    }
    else
    {
      printf("%4u|", graph->vertexArr[i]->valueID);
    }
    // Pares da matriz
    for (unsigned j = 0; j < graph->vertexArrLength; j++)
    {
      printf("%4u|", hasEdgeBetween(graph->vertexArr[i], graph->vertexArr[j]) ? 1 : 0);
    }
    printf("\n");
  }
  printf("\n");
}

// Exibe no console os detalhes principais do Vértice para o usuário.
void printVertex(Vertex *vertex)
{
  printf("/============\\\n");
  printf("|Vertex: %04u|\n", vertex->valueID);
  printf("|isExit: %04u|\n", vertex->isExit);
  printf("\\============/\n");
}

void app()
{
  // printf Tela de Apresentação.
  printf("/================\\\n");
  printf("|-- Grafirinto --| \n");
  printf("\\================/\n");

  printf("\n* Bem vindo ao Grafirinto! *\n");
  printf("* Por favor informe a dificuldade! *\n");

  // Escolha de dificuldade com getOption();
  // Criar Grafo de acordo com a dificuldade.
  Graph *graph = createGraph(getOption(3, 10));

  // Vertice inicial.
  Vertex *currentVertex = graph->vertexArr[0];

  unsigned option = 0,     // Opção da escolha dos vértices.
      hasAbandonMatch = 0; // Verifica se o usuário escolheu desistir.

  // main loop enquanto não estiver no vértice de saída.
  while (!currentVertex->isExit)
  {
    // Print vertice atual
    printVertex(currentVertex);

    // Opcional: Print [MAPA]
    printExitMap(graph, currentVertex);

    // printEdges() mostra no console os vértices para ir a partir do vértice atual.
    // getOption() retorna um unsigned no intervalo [0, currentVertex->edgeArrLength].
    // Salva a escolha do usuário para verificar se ele desistiu ou não.
    option = getOption(0, printEdges(currentVertex));
    if (option == currentVertex->edgeArrLength)
    {
      hasAbandonMatch = 1;
      break;
    }

    // ir para vértice escolhido
    currentVertex = currentVertex->edgeArr[option];
  }
  printVertex(currentVertex);
  freeGraph(graph);

  // Após ter saído do loop
  if (!hasAbandonMatch)
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
