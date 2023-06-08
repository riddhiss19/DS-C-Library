///////////////////////////////////////////////////////// SINGLY CIRCULAR LINKED LIST /////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node* newNode;
struct node* temp,*temp1,*prev;

//******************************* insert begin when empty **********************************
struct node* scl_AddANode(int val)
{
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=val;
      newNode->next = newNode;
      return newNode;
};
//******************************* circular insert begin ************************************
struct node* scl_InsertBegin(struct node* tail,int val)
{
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=val;
        newNode->next=tail->next;
        tail->next=newNode; 
        return tail;
};
//******************************* circular insert end **************************************
struct node* scl_InsertEnd(struct node* tail,int val){
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=val;
        newNode->next=tail->next;
        tail->next=newNode;
        tail=tail->next;
}
//******************************* circular insert location *********************************
struct node* scl_InsertLocation(struct node* tail,int val,int loc){
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    temp=tail->next;
        while(temp->next->data!=loc)
            temp=temp->next;
        newNode->next=temp->next->next;
        temp->next=newNode;
    return tail;
}

//******************************* circular insert before ***********************************
struct node* scl_InsertBefore(struct node* tail,int val,int loc){
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    temp=tail->next;
        while(temp->next->data!=loc)
            temp=temp->next;
        newNode->next=temp->next;
        temp->next=newNode;
    return tail;
}
//******************************* circular insert after ************************************
struct node* scl_InsertAfter(struct node* tail,int val,int loc){
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=val;
     temp=tail->next;
        while(temp->data!=loc)
            temp=temp->next;
        newNode->next=temp->next;
        temp->next=newNode;
    return tail;
}

//******************************* circular delete after *****************************************
struct node* scl_DeleteAfter(struct node* tail,int loc){
    if(tail == NULL)
        return tail;

     temp=tail->next;
        while(temp->data!=loc)
            temp=temp->next;
        temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);
        temp1=NULL;
        
    return tail;
}
//******************************* circular delete before ****************************************
struct node* scl_DeleteBefore(struct node* tail,int loc){
    if(tail == NULL)
        return tail;

     temp=tail->next;
        while(temp->next->data!=loc){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
        temp=NULL;
        
    return tail;
}
//******************************* circular delete end  ******************************************
struct node* scl_DeleteEnd(struct node* tail){
    if(tail == NULL)
        return tail;

     prev=tail->next;
        while(prev->next->next!=tail->next)
            prev=prev->next;
        temp1=prev->next;
        prev->next=temp1->next;
        free(temp1);
        temp1 = NULL;
    return tail;
}
//******************************* circular delete start  ****************************************
struct node* scl_DeleteFirst(struct node* tail){
    if(tail == NULL)
        return tail;

     temp=tail->next;
     tail->next=temp->next;
     free(temp);
     temp = NULL;
    return tail;
}
//******************************* singly circular delete at location ****************************
struct node* scl_DeleteAtLocation(struct node* tail,int loc){
    if(tail == NULL)
        return tail;
        
     temp=tail->next;
        while(temp->data!=loc){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
        temp=NULL;
        
    return tail;
}
//display_Scl
void display_Scl(struct node* tail){
       if(tail == NULL)
         printf("No node in list");
       else{
            temp=tail->next;
            do{
                printf("%d\n",temp->data);
                temp=temp->next;
            }while(temp!=tail->next);
       }
}
