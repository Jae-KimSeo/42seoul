#include "prim.h"

// 그래프를 선언하고
// 새로운 그래프를 만듬 
// 첫 노드 선택
// 노드에 대한 간선 (링크드리스트의 head 이후 element를 queue에 넣고 우선순위에 따라 정렬)
// 우선순위 뺴고 // cycle을 만들 경우 뺸다음에 다음에 찾고 다시 넣어야함 
// 

node_element* init_node_element(ListNode *node){
    node_element* ret;
    ListNode* edge;

    if (!(ret = (node_element*)malloc(sizeof(node_element))))
        return (NULL);
    edge = node_init(node->from_vertex, node->to_vertex);
    edge->weight = node->weight;

    ret->node = edge;
    ret->key = edge->weight;


    return (ret);
}



node_element* pop_priority_edge(LinkedGraph* MST, Heap *heap){
    node_element* top;
    top = heap->pElement[1];
    deleteMinHeap(heap);
    while (checkVertexValid(MST, top->node->to_vertex) == TRUE){
        top = heap->pElement[1];
        if (heap->currentElementCount != 0) {
            deleteMinHeap(heap);
        }
        else break;
        
    }
    return (top);
}





//void insertMinHeap_

LinkedGraph* prim(LinkedGraph *graph, int first_vertex){
    Heap* priority_queue;
    LinkedGraph *MST;
    ListNode **ptr;
    ListNode *node_ptr;
    node_element* min_edge;
    node_element* tmp;
    int current_vertex;

    ptr = graph->ppAdjEdge;
    MST = createLinkedGraph(100);
    priority_queue = createHeap();
        
    addVertexLG(MST, first_vertex);
    displayLinkedGraph(MST);
    current_vertex = first_vertex;
    while (MST->currentVertexCount < graph->currentVertexCount) {
        int i = 0;
    while (ptr[i]->from_vertex != current_vertex){
        i++;
    }
    
    node_ptr = ptr[i]->link;
    while (node_ptr != NULL){ //노드에 대한 간선 우선순위 큐에 추가 
        //printf("%d", node_ptr->weight);
        tmp = init_node_element(node_ptr);
        insertMinHeap(priority_queue, tmp);
        node_ptr = node_ptr->link;
    }

    min_edge = pop_priority_edge(MST, priority_queue);

    

    addVertexLG(MST, min_edge->node->to_vertex);
    addEdgewithWeightLG(MST, min_edge->node->from_vertex, min_edge->node->to_vertex, min_edge->key);
    current_vertex = min_edge->node->to_vertex;
    }
    displayLinkedGraph(MST);

    return MST;

}