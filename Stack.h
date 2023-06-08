#include <stdio.h>
#include <stdlib.h>

////////////// Using Linked List ////////////////
struct node
{
    int info;
    struct node *ptr;
}*top,*top1,*temp;

int count = 0;
char Stack_Pop();

void Stack_Push(int data)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(1*sizeof(struct node));
        top->ptr = NULL;
        top->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = top;
        temp->info = data;
        top = temp;
    }
    count++;
}

void Stack_Display()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (top1 != NULL)
    {
        printf("%d ", top1->info);
        top1 = top1->ptr;
    }
 }
 
/* Pop Operation on stack */
char Stack_Pop()
{
    top1 = top;
 
    if (top1 == NULL)
    {
        printf("\n Error : Trying to pop from empty stack");
        return 1;
    }
    else
        top1 = top1->ptr;
    char temp = top->info;
    free(top);
    top = top1;
    count--;
    
    return temp;
}
 
/* Return top element */
int Stack_TopElement()
{
    return(top->info);
}
 
/* Check if stack is empty or not */
void Stack_isEmpty()
{
    if (top == NULL)
        printf("\n Stack is empty");
    else
        printf("\n Stack is not empty with %d elements", count);
}
 
/* Destroy entire stack */
void destroy()
{
    top1 = top;
 
    while (top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1->ptr;
    }
    free(top1);
    top = NULL;
 
    printf("\n All stack elements destroyed");
    count = 0;
}