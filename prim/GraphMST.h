#ifndef GRAPHMST_H
#define GRAPHMST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode
{
	int val;
	int weight;
	struct node *next;
} Node;

typedef struct GraphEdge
{
	int weight;
	int toVertexID;
	int fromVertexID;
} Edge;

Node *addEdge(Node *head, int num, int weight);

void enqueue(Edge heap[], int size, Edge value);
void heapify(Edge heap[], int size, int index);

void deleteNode(Edge heap[], int size, int index);

Edge extractMin(Edge heap[], int size);
void prim(Node *adjacencylist[], int vertices, int edges, int startVertex, Node *MST[]);

#endif
