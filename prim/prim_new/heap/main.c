#include "./heap.h"

static int is_power_of_two(int num)
{
    return num && !((num-1) & num);
}

static void  printHeap(Heap *heap)
{
  for (int i = 1; i <= heap->currentElementCount; i++){
    printf("%d ", heap->pElement[i]->key);
   // printf("tt : %d\n", is_power_of_two(i + 1));
    if (is_power_of_two(i + 1))
      printf("\n");
    //printf("a : %d\n", i);
  }
  printf("\n");
}

/*
int main(void){
  Heap *maxHeap = createHeap();
  Heap *minHeap = createHeap();
  element data;

  data.key = 5;
  insertMaxHeap(maxHeap, data);
  data.key = 10;
  insertMaxHeap(maxHeap, data);
  data.key = 3;
  insertMaxHeap(maxHeap, data);
  data.key = 15;
  insertMaxHeap(maxHeap, data);
  data.key = 20;
  insertMaxHeap(maxHeap, data);
  data.key = 18;
  insertMaxHeap(maxHeap, data);
  data.key = 155;
  insertMaxHeap(maxHeap, data);
  data.key = 31;
  // insertMaxHeap(maxHeap, data);
  
  printf("\n");
  printf("=====MaxHeap=====\n");
  printHeap(maxHeap);
  deleteMaxHeap(maxHeap);
  printf("===MaxHeap(After delete)===\n");
  printHeap(maxHeap);
  deleteMaxHeap(maxHeap);
  printf("===MaxHeap(After delete)===\n");
  printHeap(maxHeap);
  deleteHeap(maxHeap);

  data.key = 5;
  insertMinHeap(minHeap, data);
  data.key = 10;
  insertMinHeap(minHeap, data);
  data.key = 3;
  insertMinHeap(minHeap, data);
  data.key = 15;
  insertMinHeap(minHeap, data);
  data.key = 20;
  insertMinHeap(minHeap, data);
  data.key = 18;
  insertMinHeap(minHeap, data);
  data.key = 155;
  insertMinHeap(minHeap, data);
  // data.key = 31;
  // insertMinHeap(minHeap, data);
  
  printf("\n");
  printf("=====MinHeap=====\n");
  printHeap(minHeap);
  deleteMinHeap(minHeap);
  printf("===MinHeap(delete one)===\n");
  printHeap(minHeap);
  deleteMinHeap(minHeap);
  printf("===MinHeap(delete one)===\n");
  printHeap(minHeap);
  deleteMinHeap(minHeap);
  printf("===MinHeap(delete one)===\n");
  printHeap(minHeap);
  deleteMinHeap(minHeap);
  printf("===MinHeap(delete one)===\n");
  printHeap(minHeap);
  deleteHeap(minHeap);
}*/