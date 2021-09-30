#include "GraphMST.h"

Node *addEdge(Node *head, int num, int weight)
{
	Node *pEdge = (Node*)malloc(sizeof(Node));

	pEdge->val = num;
	pEdge->next = head;
	pEdge->weight = weight;
	head = pEdge;

	return (pEdge);
}

void enqueue(Edge heap[], int size, Edge value)
{
	heap[size] = value;

	int i = size;
	Edge tmp;

	while (i >= 1)
	{
		if (heap[i / 2].weight > heap[i].weight)
		{
			tmp = heap[i / 2];
			heap[i / 2] = heap[i];
			heap[i] = tmp;

			i = i / 2;
		}
		else
		{
			break;
		}
	}
}

void heapify(Edge heap[], int size, int index)
{
	int i = index;
	Edge tmp;

	while ((2 * i) < size)
	{
		if ((2 * i) + 1 >= size)
		{
			if (heap[i].weight > heap[2 * i].weight)
			{
				tmp = heap[i];
				heap[i] = heap[2 * i];
				heap[2 * i] = tmp;

				break;
			}
		}

		if (heap[i].weight > heap[2 * i].weight || heap[i].weight > heap[2 * i + 1].weight)
		{
			if (heap[2 * i].weight <= heap[(2 * i) + 1].weight)
			{
				tmp = heap[2 * i];
				heap[2 * i] = heap[i];
				heap[i] = tmp;

				i = 2 * i;
			}
			else if (heap[2 * i].weight > heap[(2 * i) + 1].weight)
			{
				tmp = heap[(2 * i) + 1];
				heap[(2 * i) + 1] = heap[i];
				heap[i] = tmp;

				i = (2 * i) + 1;
			}
		}
		else
		{
			break;
		}
	}
}

void deleteNode(Edge heap[], int size, int index)
{
	Edge tmp = heap[index];

	heap[index] = heap[size - 1];
	heap[size - 1] = tmp;

	int i = index;
	--size;

	heapify(heap, size, i);
}

Edge extractMin(Edge heap[], int size)
{
	Edge min = heap[0];

	deleteNode(heap, size, 0);

	return min;
}

void prim(Node* adjacencylist[], int vertices, int edges, int startVertex, Node *MST[])
{
	int current = startVertex;
	int newVertex;
	int visited[vertices + 1];
	Node* tmp;
	Edge node;
	Edge priorityQueue[2 * edges];
	int queueSize = 0;

	int i;

	for (i = 0; i <= vertices; ++i)
		visited[i] = 0;

	i = 0;
	while (i < vertices)
	{
		if (visited[current] == 0)
		{
			visited[current] = 1;
			tmp = adjacencylist[current];

			while (tmp != NULL)
			{
				node.toVertexID = current;
				node.fromVertexID = tmp->val;
				node.weight = tmp->weight;
				if (!visited[node.fromVertexID])
				{
					enqueue(priorityQueue, queueSize, node);
					++queueSize;
				}
				tmp = tmp->next;
			}
			node = extractMin(priorityQueue, queueSize); // The greedy choice
			--queueSize;

			newVertex = node.fromVertexID;
			current = node.toVertexID;

			if (visited[newVertex] == 0)
			{
				MST[current] = addEdge(MST[current], newVertex, node.weight);
				MST[newVertex] = addEdge(MST[newVertex], current, node.weight);
			}
			current = newVertex;
			++i;
		}
		else
		{
			node = extractMin(priorityQueue, queueSize);
			--queueSize;
			newVertex = node.fromVertexID;
			current = node.toVertexID;

			if (visited[newVertex] == 0)
			{
				MST[current] = addEdge(MST[current], newVertex, node.weight);
				MST[newVertex] = addEdge(MST[newVertex], current, node.weight);
			}
			current = newVertex;
		}
	}
}
