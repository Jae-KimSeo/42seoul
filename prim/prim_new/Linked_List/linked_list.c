#include "linked_list.h"

ListNode* node_init(int from_vertex, int to_vertex){
	ListNode *ret;

	ret = (ListNode*)malloc(sizeof(ListNode));
	ret->from_vertex = from_vertex;
	ret->to_vertex = to_vertex;
	ret->weight = 0;
	ret->visited = FALSE;
	ret->link = NULL;

	return ret;
}

/*
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value;
	// (2)
	p->link = head; //(3)
	head = p; //(4)
	return head;
}
*/
// 노드 pre 뒤에 새로운 노드 삽입
/*
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	//(1)
	p->data = value; //(2)
	p->link = pre->link; //(3)
	pre->link = p; //(4)
	return head; //(5)
}
// 앞부분의 노드 제거
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head; // (1)
	head = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}
// pre가 가리키는 노드의 다음 노드를 삭제.
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}
// 리스트 출력
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
*/

/*
int main(void){
    ListNode **lst;
    ListNode *curr;

    lst->next = lst; // lst의 넥스트는 결국 다음줄이네 
    curr = *lst;

    tmp->next
}
// 하나의 *lst 

*/