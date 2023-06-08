#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////// DOUBLY CIRCULAR LINKED LIST /////////////////////////////////////
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* newNode,*temp,*temp1;
// 1)************************************************* dcl_AddANode *****************************************
struct node* dcl_AddANode(int val){
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->prev=newNode;
    newNode->next=newNode;
    return newNode;
}
// 2) ************************************************ insert begin ******************************************
struct node* dcl_InsertBegin(struct node*tail,int val){
    struct node* newP = dcl_AddANode(val);
    if(tail == NULL)
        return newP;
    else{
        temp=tail->next;
        newNode->next=temp;
        newNode->prev=tail;
        temp->prev=newNode;
        tail->next=newNode;
        return tail;
    }
}
// 3) ************************************************ insert end ******************************************
struct node* dcl_InsertEnd(struct node*tail,int val){
    struct node* newP = dcl_AddANode(val);
    if(tail == NULL)
        return newP;
    else{
         newNode->prev=tail;
         newNode->next=tail->next;
         tail->next->prev=newNode;
         tail->next=newNode;
         tail=tail->next;
    }
}
// 4)**************************************** insert before ******************************************
struct node* dcl_InsertBefore(struct node *tail,int val,int loc)
{
    struct node* newP = dcl_AddANode(val);
    if(tail == NULL)
        return newP;
    else{
        temp = tail->next;
        while(temp->data != loc){
            temp = temp->next;
        }
        newNode->prev=temp->prev;
        newNode->next=temp;
        temp->prev->next=newNode;
        temp->prev=newNode;
    }
    return tail;
}
// 5)******************************************* insert after ******************************************
struct node * dcl_InsertAfter(struct node *tail,int val,int loc){

    struct node* newP = dcl_AddANode(val);
    if(tail == NULL)
        return newP;
    else{
        temp = tail;
        while(temp->data != loc){
            temp = temp->next;
        }
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next->prev=newNode;
        temp->next=newNode;
    }
    return tail;
}
//6)************************************************ insert at location ***********************************
struct node * dcl_InsertAtLocation(struct node *tail,int val,int loc){
   
    struct node* newP = dcl_AddANode(val);
    if(tail == NULL)
        return newP;
    else{
        temp = tail->next;
        while(temp->data != loc){
            temp = temp->next;
        }
        
        newNode->next=temp->next;
        newNode->prev=temp->prev;
        temp->next->prev=newNode;
        temp->prev->next=newNode;
        free(temp);
        temp=NULL;
    }
    return tail;
}
// 7)************************************************ delete begin ******************************************
struct node * dcl_DeleteBegin(struct node *tail){
    if(tail == NULL)
        return tail;   
    temp=tail->next;
    if(temp==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    tail->next=temp->next;
    temp->next->prev=tail;
    free(temp);
    return tail;
}
// 8)************************************************ delete end ******************************************
struct node * dcl_DeleteEnd(struct node *tail){
    if(tail == NULL)
        return tail;   
    temp=tail->next;
    if(temp==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    temp=tail->prev;
    temp->next=tail->next;
    tail->next->prev=temp;
    free(tail);
    tail=temp;
    return tail;
}
// 9)************************************************ delete before ******************************************
struct node* dcl_DeleteBefore(struct node *tail,int loc){
    if(tail == NULL)
        return tail; 
    temp=tail->next;
    if(temp==tail){
        free(tail);
        tail=NULL;
        return tail;
    }

    while(temp->next->data != loc)
        temp = temp->next;
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp);
    return tail;
}
// 10)************************************************ delete after ******************************************
struct node* dcl_DeleteAfter(struct node *tail,int loc){
    if(tail == NULL)
        return tail; 
    temp=tail->next;
    if(temp==tail){
        free(tail);
        tail=NULL;
        return tail;
    }

    while(temp->data != loc)
        temp = temp->next;
    temp1=temp->next;
    temp->next=temp1->next;
    temp1->next->prev=temp;

    free(temp1);
    return tail;
}
// 11)************************************************ delete at loaction *************************************
struct node* dcl_DeleteAtLocation(struct node *tail,int loc){
    if(tail == NULL)
        return tail; 
    temp=tail->next;
    if(temp==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    while(temp->data != loc)
            temp = temp->next;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    temp=NULL;
    free(temp);
    return tail;
}
// 12)************************************************ display_Dcl ******************************************
void display_Dcl(struct node* tail){
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

