struct node
{
    int info;//Stores data
    struct node *back;//Backward Link
    struct node *forw;//Forward Link
} *start = NULL, *last = NULL;//Start with blank pointers or new list

void insertStart()
{
    int item;
    struct node *ptr;
    printf("\n\nAdd a student # to the roster: ");
    scanf("%d", &item);
    printf("\n\n");

    if (start == NULL)//Check for the only node
    {
        start = (struct node *) malloc(sizeof (struct node));
        last = start;
        start->info = item;
        start->back = NULL;
        start->forw = NULL;

    } else
    {
        ptr = start;
        start = (struct node *) malloc(sizeof (struct node));
        start->info = item;
        start->back = NULL;
        start->forw = ptr;
        ptr->back = start;
    }
}


//Displays the nodes info from the linked lists
void displayRoster()
{
    struct node *ptr;
    int i = 1;

    if (start == NULL)//Check if it is empty
    {
        printf("\n\nClass roster is already empty\n\n");
        
    }
    else
    {
        ptr = start;//Start with the first node to display  
        printf("\n\nStudents currently on the class roster: ");
        
        while (ptr != NULL)//Print while values exist
        {
            printf("\n%d",ptr->info);
            ptr = ptr->forw;
            
        }
        printf("\n");
    }
}

//Deletes from the front of a linked list.
void deleteStart()
{
    int item;
    struct node *ptr;

    if (start == NULL){
        printf("\n\nClass roster is already empty\n\n");
        sleep(2);
    }
    else
    {
        ptr = start;//Set the pointer to the first node
        item = start->info;//Get the first nodes info

        if (start == last)//Check for the last item in the list
        {
            start = NULL;
            last = NULL;
        } else
        {
            start = start->forw;// Point this node at the next node in the list
            start->back = NULL;//Make this node as the first in the list
        }
        free(ptr);//free the memory
        printf("\n\nStudent %d removed from the class roster!\n\n\n", item);
        
    }
}