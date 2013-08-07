#define	MAXA	35

typedef struct {
    int head, tail;
    int list[MAXA];
} Queue;

Queue *initQueue() {
    Queue *q = (Queue*) malloc(sizeof (Queue));
    q->head = q->tail = 0;
    return q;
}

int isEmptyQ(Queue *q) {
    return q->head == q->tail;
}

void enqueue(Queue *q, int n) {
    if (q->tail == MAXA - 1) {
        q->tail = 0; /*	wrap	around!	*/
    }
    else {
        q->tail++;
    }
    if (q->tail == q->head) {
        printf("Class is full\n");
        exit(1);
    }
    q->list[q->tail] = n;
}

int dequeue(Queue *q) {
    if (!isEmptyQ(q)) {
        printf("No one is in the class\n");
        exit(1);
    }
    
    int item = q->list[q->head];
    q->head++;

    printf("%d is deleted", item);
    return item;
}