
// 그래프를 선언하고
// 새로운 그래프를 만듬 
// 첫 노드 선택
// 노드에 대한 간선 (링크드리스트의 head 이후 element를 queue에 넣고 우선순위에 따라 정렬)
// 우선순위 뺴고 // cycle을 만들 경우 뺸다음에 다음에 찾고 다시 넣어야함 
// check_cycle : 현재 있는 노드들 확인, 우선순위큐 node 겹치면 걔네는 그냥 버린다 

#ifndef _PRIM_H
# define _PRIM_H

#include "heap/heap.h"
#include "graph_linked_list/graphLL.h"

LinkedGraph* prim(LinkedGraph *graph, int first_vertex);

#endif