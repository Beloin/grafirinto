#pragma once

#include <stdlib.h>

typedef struct _vertex
{
  struct _vertex **edgeArr;
  unsigned edgeArrLength;
  char *valueID;
} Vertex;

typedef struct _graph
{
  struct _vertex *vertexArr;
  unsigned vertexArrLength;
} Graph;

Vertex *newVertex(char *newValueID)
{
}

// Cria uma aresta entre os vértices A e B
void newEdge(Vertex *A, Vertex *B)
{
}

// Cria múltiplas arestas entre o vértice target os vértices em vertexArr
void newMultipleEdge(Vertex *target, Vertex *vertexArr[], unsigned vertexArrLength)
{
  for (unsigned i = 0; i < vertexArrLength; i++)
  {
    newEdge(target, vertexArr[i]);
  }
}

void freeGraph(Graph *graph)
{
}
