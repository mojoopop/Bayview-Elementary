#define	MAXA	35//Defien the max number of students for the roster


//Define a queue data type
typedef struct {
    int head, tail;
    int list[MAXA];
} Queue;

//Make a queue
Queue *initQueue() {
    Queue *q = (Queue*) malloc(sizeof (Queue));
    q->head = q->tail = 0;
    return q;
}

//Checks if the queue is empty
int isEmptyQ(Queue *q) {
    return q->head == q->tail;
}

//Adds items to the queue
int enqueue(Queue *q, int n) 
{
    if (q->tail == MAXA - 1) 
    {
        
        q->tail = 0; /*Ensures that the queue is circular*/
    }
    else {
        q->tail++;//Increses the tail by 1
    }
    if (q->tail == q->head) {
        
        printf("\nUnable able to add: Class is full\n\n");
        sleep(2);
    }
    q->list[q->tail] = n;//Asigns the passed value to the tail
    return q->list[q->tail];//Returns the value just enqueued
}

//Removes from the queue
int dequeue(Queue *q) {
    if (isEmptyQ(q)) {
        printf("No one is in the class\n");
        sleep(2);
    }
    
    int item = q->list[q->head+1];//Assigns teh value at the head of the queue to be returned after incrementation
    q->head++;  //Increments the head
    return item;//Returns the value at the head of the queue
}

//Displays the attendence
void viewAttend(Queue* q)
{
    int tempQItem;
    Queue* qTemp = initQueue();//temporary queue
    if(isEmptyQ(q))
    {
        printf("\nThere are no students in class today.\n");
        sleep(2);    
    }
    printf("\nThese students are present today: \n\n");
    while(!isEmptyQ(q))//Print until the queue is empty
    {
        tempQItem = dequeue(q);
        printf("%d\n", tempQItem);
        enqueue(qTemp,tempQItem);
        
    }
    while(!isEmptyQ(qTemp))//utitilty to enqueue in proper order
    {
        enqueue(q,dequeue(qTemp));
    }
    sleep(5);
}