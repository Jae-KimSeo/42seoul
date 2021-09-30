#ifndef _GRAPH_LINKEDLIST_
#define _GRAPH_LINKEDLIST_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_graph_def.h"
#include "queue.h"

typedef struct LinkedGraphType
{
	int maxVertexCount;		// Maximum number of Nodes
	int currentVertexCount;	// The Number of Nodes used so far
	int currentEdgeCount;	// The Number of Edges used so far
	int graphType;			// Types -> 1 : Non-directed, 2 : Directed
	ListNode** ppAdjEdge;	// 2D-LinkedList that stores Edges
	int *pVertex;			// 1D-array that stores Nodes
} LinkedGraph;

// Create a Non-Directinal Graph
// Create a Directional Graph
LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

// Remove the Graph
void deleteLinkedGraph(LinkedGraph* pGraph);

// The existence of Nodes in the Graph
int isEmptyLG(LinkedGraph* pGraph);

// Adding Nodes to the Graph
int addVertexLG(LinkedGraph* pGraph, int vertexID);

// Adding Edges to the Graph
// Adding Weights to the Graph
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// Checking Vertex is Valid
int checkVertexValid(LinkedGraph* pGraph, int vertexID);

// Remove the Node from the Graph
int removeVertexLG(LinkedGraph* pGraph, int vertexID);

// Remove Edges from the Graph
// Delete Node from the Graph
// Find Node Position from the Graph
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
void deleteGraphNode(ListNode* pList, int delVertexID);
int findGraphNodePosition(ListNode* pList, int vertexID);

// Get EdgeCount
int getEdgeCountLG(LinkedGraph* pGraph);

// Get VertexCount
int getVertexCountLG(LinkedGraph* pGraph);

// Get MaxVertexCount
int getMaxVertexCountLG(LinkedGraph* pGraph);

// Get GraphType
int getGraphTypeLG(LinkedGraph* pGraph);

// Output adjacent-List in the Graph
void displayLinkedGraph(LinkedGraph* pGraph);


ListNode *getNodeFromVertex(LinkedGraph* pGraph, element vertex);
#endif


