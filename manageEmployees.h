#define	MAX	100//Maximum number of employees	

//Define a stack
typedef struct {
    int top;//Top of stack
    int list[MAX];//Define an array with the MAX number of slots
} Stack;

//Make a stack
Stack *initStack() {
    Stack *s = (Stack*) malloc(sizeof (Stack));//Allocate memory
    s->top = -1;//Set the top to negative 1
    return s;//return the stack
}

//Checks if the stack is empty
int empty(Stack *s) {
    return s->top == -1;
}

//Adds items to the stack
int push(Stack *s, int n) {
    if (s->top == MAX - 1) {
        printf("\nStack Overflow: Fire someone to make room!\n\n");
        return 0;
    }
    s->top++;//Increase the top of the stack by 1
    s->list[s->top] = n;//Set the top of the stack to the item you provided to push
    return 1;//Return success 
}

//Deletes from the stack
int pop(Stack *s) {
    if(empty(s))
    {
        printf("\nStack Empty: No one has ever been hired!\n\n");       
        sleep(2);
    }
    return s->list[s->top--];//Negates the top by one to delete
    
}

//Looks at the next employee to be popped or fired
int peek(Stack *s) {
    if (empty(s)) {
        printf("\nStack Empty: No one has been hired!\n");
        sleep(2);
    }
    return s->list[s->top];//Returns the employee number without popping
    
}

