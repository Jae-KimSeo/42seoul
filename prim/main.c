#include "GraphMST.h"

int main()
{
	int vertices, edges, i, j, v1, v2, weight;

	printf("Enter the Number of Vertices -\n");
	scanf("%d", &vertices);

	printf("Enter the Number of Edges -\n");
	scanf("%d", &edges);

	Node *adjacencyList[vertices + 1];
	Node *MST[vertices + 1];

	for (i = 0; i <= vertices; ++i)
	{
		adjacencyList[i] = NULL;
		MST[i] = NULL;
	}

	for (i = 1; i <= edges; ++i)
	{
		scanf("%d%d%d", &v1, &v2, &weight);
		adjacencyList[v1] = addEdge(adjacencyList[v1], v2, weight); //Adding edge v1 ---W---> v2
		adjacencyList[v2] = addEdge(adjacencyList[v2], v1, weight); //Adding edge v2 ---W---> v1
	}

	// Printing Adjacency List
	printf("\nAdjacency List -\n\n");
	for (i = 0; i < vertices; ++i)
	{
		printf("adjacencyList[%d] -> ", i);

		Node *tmp = adjacencyList[i];

		while (tmp != NULL)
		{
			printf("%d (%d) -> ", tmp->val, tmp->weight);
			tmp = tmp->next;
		}

		printf("NULL\n");
	}

	int startVertex;

	printf("\nEnter a Start Vertex - ");
	scanf("%d", &startVertex);
	prim(adjacencyList, vertices, edges, startVertex, MST);

	// Printing MST
	printf("\nMinimum Spanning Tree -\n\n");
	for (i = 0; i < vertices; ++i)
	{
		printf("MST[%d] -> ", i);

		Node *tmp = MST[i];

		while (tmp != NULL)
		{
			printf("%d (%d) -> ", tmp->val, tmp->weight);
			tmp = tmp->next;
		}

		printf("NULL\n");
	}

	return 0;
}
