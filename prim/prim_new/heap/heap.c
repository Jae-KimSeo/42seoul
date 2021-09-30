#include "./heap.h"

// typedef struct {
//   int key;
// } node_element;

// typedef struct HEAP {
//   node_element pElement[MAX_NUM];
//   int currentElementCount;
// } Heap;

// Heap  *createHeap(); //heap생성
// int   deleteHeap(Heap *heap); //heap삭제
// int   insertMinHeap(Heap *heap); //MinHeap 노드 추가
// int   deleteMinHeap(Heap *heap); //MinHeap 노드 삭제
// int   insertMaxHeap(Heap *heap); //MaxHeap 노드 추가
// int   deleteMaxHeap(Heap *heap); //Max노드 삭제

Heap  *createHeap(void) {
  Heap  *newHeap;

  newHeap = (Heap *)malloc(sizeof(Heap));
  if (!newHeap)
  {
    printf("Memory allocation error!\n");
    return (NULL);
  }
  bzero(newHeap, sizeof(Heap));
  // newHeap->currentElementCount = 0;
  return (newHeap);
}

int insertMaxHeap (Heap *heap, node_element* data) { 
// NULL guard
  if (!heap)
  {
    printf("Heap does not exist!\n");
    return (FALSE);
  }

// Step-1) 트리의 마지막 자리에 임시 저장 
  int i;

  heap->currentElementCount = heap->currentElementCount + 1;
  i = heap->currentElementCount;
// Step-2) 부모 노드와 키 값 비교 및 이동 
  while ((i != 1) && (data->key > heap->pElement[i / 2]->key))
  {
    heap->pElement[i] = heap->pElement[i / 2];
    i = i / 2;
  }
  heap->pElement[i] = data;
  return (TRUE);
}

int deleteMaxHeap(Heap *heap) //삭제는 항상 루트노드에서
{
  int parent = 1;
  int child = 2;
  int tmp = heap->pElement[heap->currentElementCount]->key;
  // NULL guard
  if (!heap)
  {
    printf("Heap does not exist!\n");
    return (FALSE);
  }
  // 1 루트 삭제
  // 2 마지막 인덱스 값 루트로 이동
  // heap->pElement[1] = heap->pElement[heap->currentElementCount];
  heap->currentElementCount--;
  // 키 값 비교하면서 reordering
  while (child <= heap->currentElementCount)
  {
    if ((child < heap->currentElementCount) 
    && heap->pElement[child]->key < heap->pElement[child + 1]->key)
      child += 1;
    if (tmp >= heap->pElement[child]->key)
      break ;
    heap->pElement[parent] = heap->pElement[child];
    parent = child;
    child *= 2;
  }
  heap->pElement[parent]->key = tmp;
  return (TRUE);
}

int insertMinHeap (Heap *heap, node_element* data) { 
// NULL guard
  if (!heap)
  {
    printf("Heap does not exist!\n");
    return (FALSE);
  }
// Step-1) 트리의 마지막 자리에 임시 저장 
  int i;

  heap->currentElementCount = heap->currentElementCount + 1;
  i = heap->currentElementCount;
// Step-2) 부모 노드와 키 값 비교 및 이동 
  while ((i != 1) && (data->key < heap->pElement[i / 2]->key))
  {
    heap->pElement[i] = heap->pElement[i / 2];
    i = i / 2;
  }
  heap->pElement[i] = data;
  return (TRUE);
}

int deleteMinHeap(Heap *heap) //삭제는 항상 루트노드에서
{
  int parent = 1;
  int child = 2;
  int tmp = heap->pElement[heap->currentElementCount]->key;
  // NULL guard
  if (!heap)
  {
    printf("Heap does not exist!\n");
    return (FALSE);
  }
  // 1 루트 삭제
  // 2 마지막 인덱스 값 루트로 이동
  // heap->pElement[1] = heap->pElement[heap->currentElementCount];
  heap->currentElementCount--;
  // 키 값 비교하면서 reordering
  // 마지막 노드 형제가 없는 경우(홀수인 경우) 되는 경우 때문에 = 이 들어가야함 -> 개소리였다
  // = 이 들어가야하는 이유 : 내 형제와의 상속 issue <<
  while (child <= heap->currentElementCount)
  {
    if ((child < heap->currentElementCount) 
    && heap->pElement[child]->key > heap->pElement[child + 1]->key)
      child += 1;
    if (tmp <= heap->pElement[child]->key)
      break ;
    heap->pElement[parent] = heap->pElement[child];
    parent = child;
    child *= 2;
  }
  heap->pElement[parent]->key = tmp;
  return (TRUE);
}

int deleteHeap(Heap *heap)
{
  if (!heap)
  {
    printf("Heap does not exist!\n");
    return (FALSE);
  }
  free(heap);
  heap = NULL;

  return (TRUE);
}