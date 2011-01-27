#include "queue.h"

void QueueInit(ZQUEUE *q)
{
	q->head=0;
	q->tail=0;
}

unsigned char QueueIsEmpty(ZQUEUE* q)
{
	return(q->tail==q->head);
}

unsigned char QueueIsFull(ZQUEUE* q)
{
	return((q->tail+1)%QUEUE_MAX)==q->head; 
}

unsigned char QueueInsert(ZQUEUE* q,unsigned char item)
{
	if(!QueueIsFull(q))
	{
		q->item[q->tail]=item;
		q->tail=(q->tail+1)%QUEUE_MAX;
		return 1;
	}
	return 0;
}

unsigned char QueueDelete(ZQUEUE *q,unsigned char *item)
{
	if(!QueueIsEmpty(q))
	{
		*item=q->item[q->head];
		q->head=(q->head+1)%QUEUE_MAX;
		return 1;
	}
	return 0;
}


