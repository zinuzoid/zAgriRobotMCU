
#define QUEUE_MAX 100

typedef struct
{
	unsigned char item[QUEUE_MAX];
	unsigned char head;
	unsigned char tail;
}ZQUEUE;

void QueueInit(ZQUEUE *q);
unsigned char QueueIsEmpty(ZQUEUE* q);
unsigned char QueueIsFull(ZQUEUE* q);
unsigned char QueueInsert(ZQUEUE* q,unsigned char item);
unsigned char QueueDelete(ZQUEUE *q,unsigned char *item);

