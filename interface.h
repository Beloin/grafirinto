#pragma once

#include "graph.h"

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
  
  return vertex->edgeArrLength + 1;
}

void printVertex(Vertex *vertex)
{
  printf("/============\\\n");
  printf("|Vertex: %04u|\n", vertex->valueID);
  printf("|isExit: %04u|\n", vertex->isExit);
  printf("\\============/\n");
}

/* 
 *  Com base na quantidade de opções, verifica se
 * o usuário escolheu uma opção válida e a retorna 
*/
unsigned getOption(unsigned numberOfOptions)
{
  unsigned option = 0;
  do
  {
    printf("Por favor, informe um natural que pertence ao intervalo [0, %u]: ", numberOfOptions);
    scanf("%u", &option);
  } while (option > numberOfOptions);

  return option;
}

void app()
{
  // printf Tela de Apresentação.
  printf("/================\\\n");
  printf("|-- Grafirinto --| \n");
  printf("\\================/\n");
  
  printf("\n* Bem vindo ao Grafirinto! *\n");
  printf("* Por favor informe a dificuldade! *\n");
  // Escolha de dificuldade getOption();
  // criar Grafo de acordo com a dificuldade.
  Graph *graph = createGraph(getOption(10));

  // Vertice atual.
  Vertex *currentVertex = graph->vertexArr[0];

  // Opção da escolha dos vértices.
  unsigned option = 0;

  // Verifica se o usuário escolheu desistir.
  unsigned hasAbandonMatch = 0;

  // main loop => Enquanto não estiver na saída.
  while (!currentVertex->isExit)
  {
    // Print vertice atual: printVertex();
    printVertex(currentVertex);

    // Opcional: Print [MAPA]

    // printEdges() mostra os vértices para ir a partir do atual.
    // getOption(); // incluir opção desistência
    option = getOption(printEdges(currentVertex));
    if (option > currentVertex->edgeArrLength)
    {
      hasAbandonMatch = 1;
      break;
    }

    // ir para vértice escolhido
    currentVertex = currentVertex->edgeArr[option];
  }
  printVertex(currentVertex);
  freeGraph(graph);

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