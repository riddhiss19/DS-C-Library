//////////////////////////////////////////////////////////////// SINGLY LINKED LIST ///////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *p,*temp,*temp1,*prev;

//****************************************************** add first ****************************************
struct node * sll_addFirst(struct node **head, int val)
{
      struct node *newNode = (struct node*)malloc(sizeof(struct node));
      newNode->data = val;

      newNode->next = *head;

      *head = newNode;
      return *head;
}
//****************************************************** add end ****************************************
struct node * ssl_addend(struct node **head,int val){

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

     if(*head == NULL)
         *head = newNode;
    else
    {
        temp = *head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode; 
    }
    return *head;
}
//****************************************************** add after ****************************************
struct node * sll_addafter(struct node **head,int val,int loc){

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

     if(*head == NULL)
         *head = newNode;
    else
    {   
        temp = *head;
        while(temp->data != loc)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return *head;
}
//****************************************************** add before ****************************************
struct node * sll_addbefore(struct node **head,int val,int loc){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if(*head == NULL)
        *head = newNode;
    else{
        temp = *head;
        while(temp->next->data != loc)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return *head;
}
//****************************************************** add at location *********************************
struct node * sll_add_at_location(struct node **head,int val,int loc){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if(*head == NULL)
        *head = newNode;
    else{
        temp = *head;
        while(temp->next->data != loc)
            temp = temp->next;
        temp1 = temp->next;
        newNode->next = temp1->next;
        temp->next = newNode;
    }
    return *head;
}
//****************************************************** print *******************************************
void sll_printList(struct node *head)
{
    temp = head;
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}
//****************************************************** delete first **************************************
struct node * sll_delete_first(struct node **head){
    if(*head==NULL)
        printf("List is empty.Cannot delete node");
    else
    {
    temp = *head;
    *head=temp->next;
    free(temp);
    }
    return *head;
}
//****************************************************** delete end ****************************************
struct node* sll_delete_end(struct node **head){
    if(*head==NULL)
        printf("List is empty.Cannot delete node");
    else{
    temp = *head;
    while(temp->next->next != NULL)
        temp=temp->next;
    temp1=temp->next;
    temp->next=NULL;
    free(temp1);
    }
    return *head;
}
//****************************************************** delete after **************************************
struct node * sll_delete_after(struct node **head,int loc){
   if(*head==NULL)
        printf("List is empty.Cannot delete node");
    else{
    temp = *head;
    while(temp->data != loc)
        temp = temp->next;
    temp1=temp->next;
    temp->next = temp1->next;
    free(temp1);
    }
   

    return *head;
}
//****************************************************** delete before *************************************
struct node * sll_delete_before(struct node **head,int loc){
    if(*head==NULL)
        printf("List is empty.Cannot delete node");
    else{
    temp = *head;
    while(temp->next->next->data != loc)
        temp = temp->next;
    temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
    }
    return *head;
}
//****************************************************** delete at location ********************************
struct node * sll_delete_at_location(struct node **head,int loc){
    if(*head==NULL)
        printf("List is empty.Cannot delete node");

    else{
        temp = *head;
    
    while(temp->data != loc)
    {   prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    }
    return *head;
}
