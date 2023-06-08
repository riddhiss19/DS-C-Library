#include<stdlib.h>
#include<stdio.h>
#define MAX 50

//Single Ended Queue
void create_SEQ(int *front, int *rear)
{
    *front = *rear = 0;
}

void insert_SEQ(int *q,int *rear, int element)
{
    q[(*rear)++] = element;
}

int delete_SEQ(int *q,int *front)
{
    return q[(*front)++];
}

int isFull_SEQ(int *rear)
{
    if(rear == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty_SEQ(int front, int rear)
{
    if(rear != MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void display_SEQ(int *q,int front,int rear)
{
    int i = rear-1;
    while(i >= front)
        printf("%d ",q[i--]);
}

int size_SEQ(int *front,int *rear)
{
   int temp = *rear-*front;
   return temp;
}
//Double Ended Queue
/* create object of type 'dequeue' in the .c file to use functions */
typedef struct dequeue
{
    int data[MAX];
    int rear,front;
}dequeue;

void create_DEQ(struct dequeue *block)
{
    block->rear=-1;
    block->front=-1;
}
int isEmpty_DEQ(struct dequeue *block)
{
    if(block->rear==-1)
        return(1);

    return(0);
}
int isFull_DEQ(struct dequeue *block)
{
    if((block->rear+1)%MAX==block->front)
        return(1);

    return(0);
}
void insertRear_DEQ(struct dequeue *block,int data)
{
    if(isEmpty_DEQ(block))
    {
        block->rear=0;
        block->front=0;
        block->data[0]=data;
    }
    else
    {
        block->rear=(block->rear+1)%MAX;
        block->data[block->rear]=data;
    }
}
void insertFront_DEQ(struct dequeue *block,int data)
{
    if(isEmpty_DEQ(block))
    {
        block->rear=0;
        block->front=0;
        block->data[0]=data;
    }
    else
    {
        block->front=(block->front-1+MAX)%MAX;
        block->data[block->front]=data;
    }
}
int deleteFront_DEQ(struct dequeue *block)
{
    int data;
    data=block->data[block->front];
    if(block->rear==block->front)
        create_DEQ(block);
    else
        block->front=(block->front+1)%MAX;
    return(data);
}

int deleteRear_DEQ(struct dequeue *block)
{
    int data;
    data=block->data[block->rear];
    if(block->rear==block->front)
        create_DEQ(block);
    else
        block->rear=(block->rear-1+MAX)%MAX;
    return(data);
}
void display_DEQ(struct dequeue *block)
{
    if(isEmpty_DEQ(block))
    {
        printf("\nQueue is isEmpty_DEQ!");
        exit(0);
    }
    int i=block->front;
    while(i!=block->rear)
    {
        printf("\n%d",block->data[i]);
        i=(i+1)%MAX;
    }
    printf("\n%d\n",block->data[block->rear]);
}

//Circular Queue

struct node
{
        int info;
        struct node *link;
}*rear=NULL;
int isEmpty_CQ()
{
        if( rear == NULL )
                return 1;
        else
                return 0;
}

void insert_CQ(int item)
{
        struct node *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=item;
        if(tmp==NULL)
        {
                printf("\nMemory not available\n");
                return;
        }

        if( isEmpty_CQ() )
        {
                rear=tmp;
                tmp->link=rear;
        }
        else
        {
                tmp->link=rear->link;
                rear->link=tmp;
                rear=tmp;
        }
}
int delete_CQ()
{
        int item;
        struct node *tmp;
        if( isEmpty_CQ() )
        {
                printf("\nQueue underflow\n");
                exit(1);
        }
        if(rear->link==rear) 
        {
                tmp=rear;
                rear=NULL;
        }
        else
        {
                tmp=rear->link;
                rear->link=rear->link->link;
        }
        item=tmp->info;
        free(tmp);
        return item;
}
int peek_CQ()
{
        if(isEmpty_CQ())
        {
                printf("\nQueue underflow");
                exit(1);
        }
        return rear->link->info;
}
void display_CQ()
{
        struct node *p;
        if(isEmpty_CQ())
        {
                printf("\nQueue is empty");
                return;
        }
        printf("\nQueue is :\n");
        p=rear->link;
        do
        {
                printf("%d  ",p->info);
                p=p->link;
        }while(p!=rear->link);
        printf("\n");
}
