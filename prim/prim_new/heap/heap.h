#ifndef HEAP_H
# define HEAP_H

# define MAX_NUM  256
# define TRUE     1
# define FALSE    0

# include <strings.h>
# include <stdio.h>
# include <stdlib.h>
#include "../graph_linked_list/queue.h"


typedef struct {
  ListNode *node;
  int key;
} node_element;

typedef struct HEAP {
  node_element* pElement[MAX_NUM];
  int currentElementCount;
} Heap;

Heap  *createHeap(void); //heap생성
int   deleteHeap(Heap *heap); //heap삭제
int   insertMinHeap(Heap *heap, node_element* data); //MinHeap 노드 추가
int   deleteMinHeap(Heap *heap); //MinHeap 노드 삭제
int   insertMaxHeap(Heap *heap, node_element* data); //MaxHeap 노드 추가
int   deleteMaxHeap(Heap *heap); //Max노드 삭제

#endif