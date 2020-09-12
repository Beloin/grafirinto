#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _vertex
{
  struct _vertex **edgeArr;
  unsigned edgeArrLength, valueID, isExit;
} Vertex;

typedef struct _graph
{
  struct _vertex **vertexArr;
  unsigned vertexArrLength;
} Graph;

// Checa se há item duplicado
int checkDuplicate(int arr[], int size, int value)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == value)
    {
      return 1;
    }
  }
  return 0;
}

// Verifica se o Vértice A possui uma aresta com o Vértice B
int hasEdgeBetween(Vertex *A, Vertex *B)
{
  for (unsigned i = 0; i < A->edgeArrLength; i++)
  {
    if (A->edgeArr[i] == B)
    {
      return 1;
    }
  }
  return 0;
}

// Cria um Vétice novo.
Vertex *newVertex(unsigned newValueID)
{
  // Aloca um novo Vértice
  Vertex *vertex = NULL;
  do
  {
    vertex = (Vertex *)malloc(sizeof(Vertex));
  } while (vertex == NULL);

  // Inicializa os valores do Vértice
  vertex->isExit = 0;
  vertex->edgeArr = NULL;
  vertex->edgeArrLength = 0;
  vertex->valueID = newValueID;

  return vertex;
}

// Cria um Grafo novo
Graph *newGraph(unsigned numberOfVertices)
{
  // Aloca um novo Grafo
  Graph *graph = NULL;
  do
  {
    graph = (Graph *)malloc(sizeof(Graph));
  } while (graph == NULL);

  // Aloca um novo array de Vértices
  graph->vertexArr = NULL;
  do
  {
    graph->vertexArr = (Vertex **)malloc(numberOfVertices * sizeof(Vertex *));
  } while (graph->vertexArr == NULL);

  // Inicializa os valueID e isExit dos vertices alocados
  for (unsigned i = 0; i < numberOfVertices; i++)
  {
    graph->vertexArr[i] = newVertex(i);
  }

  graph->vertexArrLength = numberOfVertices;
  return graph;
}

// Cria uma aresta entre os vértices A e B
void newEdge(Vertex *A, Vertex *B)
{
  if (!hasEdgeBetween(A, B))
  {
    A->edgeArrLength++;
    B->edgeArrLength++;

    A->edgeArr = (Vertex **)realloc(A->edgeArr, A->edgeArrLength * sizeof(Vertex *));
    B->edgeArr = (Vertex **)realloc(B->edgeArr, B->edgeArrLength * sizeof(Vertex *));

    A->edgeArr[A->edgeArrLength - 1] = B;
    B->edgeArr[B->edgeArrLength - 1] = A;
  }
}

// Cria múltiplas arestas entre o vértice target os vértices em vertexArr
void newMultipleEdge(Vertex *target, Vertex *vertexArr[], unsigned vertexArrLength)
{
  for (unsigned i = 0; i < vertexArrLength; i++)
  {
    newEdge(target, vertexArr[i]);
  }
}

Graph *createGraph(unsigned difficult)
{
  printf("Debug.\n");
  Graph *graph = (Graph *)malloc(sizeof(Graph));

  graph->vertexArrLength = difficult * 3;

  // Array de vértices principais, intuito de debug.
  Vertex **principais = (Vertex **)malloc(graph->vertexArrLength * sizeof(Vertex *));

  srand(NULL);

  // Variáveis para ver se há repetição.
  int integerNames[graph->vertexArrLength];
  int integersNamesSize = 0;

  // Cria os vertices com nome de caverna_ + random.
  for (int i = 0; i < difficult; i++)
  {
    int rand;
    // Impede repetição
    do
    {
      rand = (int)(random() % 10000);
    } while (checkDuplicate(integerNames, integersNamesSize, rand));

    integerNames[integersNamesSize] = rand;
    integersNamesSize++;

    principais[i] = newVertex(rand);
  }

  // Cria a sequência principal.
  for (int i = 1; i < difficult; i++)
  {
    Vertex *atual = principais[i - 1];
    newEdge(atual, principais[i]);
  }

  // Atribui o último
  principais[difficult - 1]->isExit = 1;

  // Cria os Vertices de distração
  for (int i = difficult; i < graph->vertexArrLength; i++)
  {
    int rand;
    // Impede repetição
    do
    {
      rand = (int)(random() % 10000);
    } while (checkDuplicate(integerNames, integersNamesSize, rand));

    integerNames[integersNamesSize] = rand;
    integersNamesSize++;

    principais[i] = newVertex(rand);
  }

  // Colocar os vértices de distração de forma randômica nos vertices principais
  for (int i = difficult; i < graph->vertexArrLength; i++)
  {
    for (int j = 0; j < graph->vertexArrLength; j++)
    {
      if (i != j)
      {
        int chance = (int)random() % 100;
        if (chance < 50)
        {
          // Impedir duplicadas.
          newEdge(principais[i], principais[j]);
        }
      }
    }
  }

  for (int i = 0; i < graph->vertexArrLength; i++)
  {
    if (i == difficult)
    {
      printf("\nDistração:\n");
    }
    printf("Valor: %d\n", graph->vertexArr[i]);
  }

  graph->vertexArr = principais;
  return graph;
}

// Libera da memória o Grafo atual.
void freeGraph(Graph *graph)
{
  int aux = graph->vertexArrLength;
  for (int i = 0; i < aux; i++)
  {
    Vertex *vert = graph->vertexArr[i];
    free(vert->edgeArr);
    free(vert);
  }
  free(graph);
}
