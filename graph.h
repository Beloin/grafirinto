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

// Libera da memória o Grafo atual.
void freeGraph(Graph *graph)
{
  for (unsigned i = 0; i < graph->vertexArrLength; i++)
  {
    Vertex *vert = graph->vertexArr[i];
    free(vert->edgeArr);
    free(vert);
  }
  free(graph->vertexArr);
  free(graph);
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

Graph *createGraph(unsigned difficult)
{
  Graph *graph = newGraph(difficult * 3);

  // Cria a sequência principal, um caminho do vértice inicial à saída
  for (int i = 1; i < difficult; i++)
  {
    Vertex *atual = graph->vertexArr[i - 1];
    newEdge(atual, graph->vertexArr[i]);
  }

  // Atribui o último Vértice da sequência principal como saída do grafirinto
  graph->vertexArr[difficult - 1]->isExit = 1;

  srand((unsigned)(NULL));

  // Cria arestas com os vértices de distração de forma randômica entre os vertices graph->vertexArr
  for (unsigned i = difficult; i < graph->vertexArrLength; i++)
  {
    for (unsigned j = 0; j < graph->vertexArrLength; j++)
    {
      if (i != j)
      {
        unsigned chance = (unsigned)(random() % 100);
        if (chance < 50)
        {
          newEdge(graph->vertexArr[i], graph->vertexArr[j]);
        }
      }
    }
  }

  return graph;
}

// // Checa se há item duplicado
// int checkDuplicate(int arr[], int size, int value)
// {
//   for (int i = 0; i < size; i++)
//   {
//     if (arr[i] == value)
//     {
//       return 1;
//     }
//   }
//   return 0;
// }

// // Cria múltiplas arestas entre o vértice target os vértices em vertexArr
// void newMultipleEdge(Vertex *target, Vertex *vertexArr[], unsigned vertexArrLength)
// {
//   for (unsigned i = 0; i < vertexArrLength; i++)
//   {
//     newEdge(target, vertexArr[i]);
//   }
// }
