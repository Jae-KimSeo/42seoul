#ifndef QUEUE_H
# define QUEUE_H
#include <stdlib.h>
#include "../Linked_List/linked_list.h"

/*
** 일종의 리스트
** 삽입과 한 쪽끝, 삭제는 반대쪽 끝에서 일어난다.
** 삽입이 일어나는 쪽을 rear, 삭제가 일어나는 쪽을 front
** FIFO, Fist In First Out
*/

# define TRUE 1
# define FALSE 0
# define ERROR -1

/* void* should be changed. b4 use. */
typedef int	Value;

typedef struct s_node
{
	Value			value;
	struct s_node	*next;
}t_node;

typedef struct s_queue
{
	size_t	queue_size;
	ListNode	*front;
	ListNode	*rear;
}t_queue;

Value		queue_top(t_queue *queue);
Value		queue_pop(t_queue *queue);
size_t		queue_push(t_queue *queue, Value value);
size_t		queue_size(t_queue *queue);
int			queue_empty(t_queue *queue);
t_queue		*init_queue();

/*
** empty : Test whether container is empty (public member function )
** size :Return size (public member function )
** front(peek, element) : Access next element (public member function )
** back : Access last element (public member function )
** push(insert, enqueue, offer) : Insert element (public member function )
** pop(remove, dequeue, poll) : Remove next element (public member function )
*/

#endif