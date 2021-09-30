#include "queue.h"


Value		queue_top(t_queue *queue) {
	if (queue == NULL || queue->front == NULL)
		return (ERROR);
	return (queue->front->from_vertex);
}

Value		queue_pop(t_queue *queue) {
	if (queue == NULL || queue->front == NULL)
		return (ERROR);

	ListNode *tmp = queue->front;
	Value	tmp_value = tmp->from_vertex;

	queue->front = queue->front->link;
	queue->queue_size--;
	if (!queue->queue_size)
		queue->rear = NULL;
	free(tmp);
	return (tmp_value);
}

size_t		queue_push(t_queue *queue, Value value) {
	if (queue == NULL)
		return (ERROR);

	ListNode	*new_one = node_init(value, '\0');

	if (new_one == NULL)
		return (0);
	if (queue->front == NULL)
	{
		queue->front = new_one;
		queue->rear = new_one;
		queue->queue_size = 1;
	}
	else
	{
		queue->rear->link = new_one;
		queue->rear = new_one;
		queue->queue_size++;
	}
	return (queue->queue_size);
}

size_t		queue_size(t_queue *queue) {
	if (queue == NULL)
		return (ERROR);
	return (queue->queue_size);
}

int			queue_empty(t_queue *queue) {
	if (queue == NULL)
		return (ERROR);
	if (queue->queue_size)
		return (FALSE);
	return (TRUE);
}

t_queue*	init_queue() {
	t_queue	*new = malloc(sizeof(t_queue));

	if (new == NULL)
		return (NULL);
	new->front = NULL;
	new->rear = NULL;
	new->queue_size = 0;
	return (new);
}