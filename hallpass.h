#define	MAX	2	

typedef struct {
    int top;
    int list[MAX];
} Stack;

Stack *initStack() {
    Stack *s = (Stack*) malloc(sizeof (Stack));
    s->top = -1;
    return s;
}

int empty(Stack *s) {
    return s->top == -1;
}

int push(Stack *s, int n) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow: Permission denied, please wait for someone to come back!\n");
        return 0;
    }
    s->top++;
    s->list[s->top] = n;
    return 1;
    
}

int pop(Stack *s) {
    if(empty(s))
    {
        printf("\nStack Empty: Everyone is in class\n");       
    }
    return s->list[s->top--];
}

int peek(Stack *s) {
    if (empty(s)) {
        printf("\nStack Empty: Everyone is in class\n");
    }
    return s->list[s->top];
}

