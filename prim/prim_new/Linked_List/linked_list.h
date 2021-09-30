#define LINKED_LIST
# ifndef LINKED_LSIT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common_graph_def.h"

typedef int element;
// 노드 타입을 구조체로 정의한다.
typedef struct ListNode { 
	element from_vertex;
	element to_vertex;
	element weight;
	int		visited;
	struct ListNode* link;
} ListNode;
// 앞부분에 노드 삽입

ListNode* node_init(int from_vertex, int to_vertex);


#endif