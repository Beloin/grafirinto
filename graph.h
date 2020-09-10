#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _vertex
{
  struct _vertex **edgeArr;
  unsigned edgeArrLength;
  char *valueID;
} Vertex;

typedef struct _graph
{
  struct _vertex **vertexArr;
  unsigned vertexArrLength;
} Graph;

// Cria um Vétice novo.
Vertex *newVertex(char *newValueID)
{
  Vertex *vertex = (Vertex *)malloc(sizeof(Vertex));
  strcpy(vertex->valueID, newValueID);
  free(newValueID);
  return vertex;
}

// Cria uma aresta entre os vértices A e B
void newEdge(Vertex *A, Vertex *B)
{
  int auxA = A->edgeArrLength;
  int auxB = B->edgeArrLength;

  A->edgeArr[auxA] = B;
  B->edgeArr[auxB] = A;

  A->edgeArrLength++;
  B->edgeArrLength++;
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
  Graph *graph = (Graph *)malloc(sizeof(Graph));

  // Array de vértices principais.
  Vertex **principais;

  srand(NULL);

  // Variáveis para ver se há repetição.
  int integerNames[difficult * 3];
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

    char *name;

    sprintf(name, "caverna_%d", rand);

    principais[i] = newVertex(name);
  }

  // Cria a sequência principal.
  for (int i = 1; i < difficult; i++)
  {
    Vertex *atual = principais[i - 1];
    newEdge(atual, principais[i]);
  }

  // Array de vértices de distração.
  Vertex **distratores;
  int qntdDist = difficult * 2;

  // Cria os Vertices de distração
  for (int i = 0; i < qntdDist; i++)
  {
    int rand;
    // Impede repetição
    do
    {
      rand = (int)(random() % 10000);
    } while (checkDuplicate(integerNames, integersNamesSize, rand));
    integerNames[integersNamesSize] = rand;
    integersNamesSize++;

    char *name;
    sprintf(name, "caverna_%d", rand);
    distratores[i] = newVertex(name);
  }

  // Coloca os vértices de distração de forma randômica nos vertices principais
  // e também adiciona os vértices de distração à lista dos vértices principais.
  /*
    Implementar
  */

  graph->vertexArr = principais;
  graph->vertexArrLength += qntdDist + difficult;
  return graph;
}

// Libera da memória o Grafo atual.
void freeGraph(Graph *graph)
{
  int aux = graph->vertexArrLength;
  for (int i = 0; i < aux; i++)
  {
    Vertex *vert = graph->vertexArr[i];
    free(vert);
  }
  free(graph);
}

int checkDuplicate(int arr[], int size, int value)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == value)
    {
      return 0;
    }
  }
  return 1;
}