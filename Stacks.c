#include "lab7.h"

typedef struct node 
{
    void * data;
    struct node *next;
}Node;

struct Info
{
    int size;
    struct node *top;
};


/*This initStack() function will initializes and returns a Stack. If initialization fails, the info pointer is
set to NULL*/

Stack initStack()
{
    //creates a stack with info pointer
    Stack s;
    s.info=malloc(sizeof(Info));
    //if it works everyting inside is initialized
    if(s.info)
    {
        s.info->top=NULL;
        s.info->size=0;
        return s;
    }
    //else it will be set to NULL
    s.info=NULL;
    return s;
}

/*The getSize function will simply return the size of the stack that was passed*/

int getSize(Stack s)
{
    return s.info->size;
}

/*The peekStack function will simply return the data of the top of the stack that was passed*/

void * peekStack(Stack s)
{
    return s.info->top->data;
}


/*The pushStack function is passed a stack and a data item. It will put the data item at the top of
the stack and return 0 if it was successful, returns 1 if not successful*/ 

int pushStack(Stack s, void *data)
{
    //creates a new node and puts the data into it
    Node * p=malloc(sizeof(Node));
    p->data=data;
    //if statement checks to see if it will be the only item in the stack
    if(s.info->size==0)
    {
        p->next=NULL;
        s.info->top=p;
        s.info->size++;
        return 0;
    }
    //if statement checks if other items in stack and will place data at the top
    if(s.info->size>0)
    {
        p->next=s.info->top;
        s.info->top=p;
        s.info->size++;
        return 0;
    }
    return 1;
}

/*The popStack function will pop off the item at the top of the stack that was passed and
return the item that was popped off*/

void * popStack(Stack s)
{
    //if statement checks if the stack is empty
    if(s.info->size==0)
    {
        return NULL;
    }
    void * temp;
    Node * node;
    //if statement checks if there is only one item in stack
    if(s.info->size==1)
    {
        //pops the item at the top, sets top to NULL
        temp=s.info->top->data;
        node=s.info->top;
        s.info->top=NULL;
        s.info->size--;
        free(node);
        return temp;
    }
    //pops the item at the top, next item is the new top
    temp=s.info->top->data;
    node=s.info->top;
    s.info->top=s.info->top->next;
    s.info->size--;
    free(node);
    return temp;   
}

/*The getAtIndex function is passed a stack and an index, it will then return the item at that index*/

void * getAtIndex(Stack s, int index)
{
    //checks to see if the index is valid
    if(index>=s.info->size)
    {
        return NULL;
    }
    //goes through the stack to get to the index location and return value
    Stack p=s;
    int i;
    for(i=0;i<index;i++)
    {
        p.info->top=p.info->top->next;
    }
    return p.info->top;
}

/*The freeStack function frees the stack that was passed*/

void freeStack(Stack s)
{
    //while loop goes through each node to free
    while(s.info->size!=0)
    {
        Node * temp=s.info->top;
        s.info->top=s.info->top->next;
        s.info->size--;
        free(temp);
    }
    //info pointer also gets freed
    s.info->top=NULL;
    s.info->size=0;
    Info * info=s.info;
    s.info=NULL;
    free(info);
}
