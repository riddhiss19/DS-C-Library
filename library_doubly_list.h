////////////////////////////////////////////////////////////////// DOUBLY LINKED LIST ///////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *p,*newNode,*temp,*nextNode,*temp1;

//******************************* doubly insert begin ************************************
struct node * dll_InsertBegin(struct node **head,int val){
    newNode =  (struct node*)malloc(sizeof(struct node));
    newNode->data = val;

    if(*head == NULL){
        *head = newNode;
        newNode->prev=NULL;
        newNode->next=NULL;
    }
    else{
        temp = *head;
        newNode->next = temp;
        temp->prev=newNode;
        *head=newNode;
    }
    return *head;
}
//******************************* doubly insert end **************************************
struct node * dll_InsertEnd(struct node **head,int val){
    newNode =  (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    

    if(*head==NULL){
        *head = newNode;
        newNode->prev=NULL;
        newNode->next=NULL; 
    }else{
        temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next=NULL;

    }
    return *head;
}
//******************************* doubly insert location *********************************
struct node * dll_InsertAtLocation(struct node **head,int val,int loc){
    newNode =  (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    
    if(*head==NULL){
        *head = newNode;
        newNode->prev=NULL;
        newNode->next=NULL; 
    }else{
        temp = *head;
        while(temp->data != loc){
            temp = temp->next;
        }
        
        newNode->next=temp->next;
        newNode->prev=temp->prev;
        temp->next->prev=newNode;
        temp->prev->next=newNode;
    }
    return *head;
}
//******************************* doubly insert before ***********************************
struct node * dll_InsertBefore(struct node **head,int val,int loc){
    newNode =  (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    
    if(*head==NULL){
        *head = newNode;
        newNode->prev=NULL;
        newNode->next=NULL; 
    }else{
        temp = *head;
        while(temp->data != loc){
            temp = temp->next;
        }
        newNode->prev=temp->prev;
        newNode->next=temp;
        temp->prev->next=newNode;
        temp->prev=newNode;
    }
    return *head;
}
//******************************* doubly insert after ************************************
struct node * dll_InsertAfter(struct node *head,int val,int loc){
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    
    if(head==NULL){
        head = newNode;
        newNode->prev=NULL;
        newNode->next=NULL; 
    }else{
        temp = head;
        while(temp->data != loc){
            temp = temp->next;
        }
        newNode->prev=temp;
        newNode->next=temp->next;
        temp->next=newNode;
        temp->next->prev=newNode;
    }
    return head;
}
//******************************* doubly delete location *****************************************
struct node * dll_DeleteAtLocation(struct node **head,int loc){
    if(*head==NULL){
       printf("List is empty");
    }else{
        temp = *head;
        while(temp->data != loc){
            temp = temp->next;
        }

       temp->next->prev=temp->prev;
       temp->prev->next=temp->next;
       free(temp);
    }
    return *head;
}
//******************************* doubly delete before ****************************************
struct node * dll_DeleteBefore(struct node **head,int loc){
    if(*head==NULL){
       printf("List is empty");
    }else{
        temp = *head;
        while(temp->next->data != loc){
            temp = temp->next;
        }
        temp->next->prev=temp->prev;
       temp->prev->next=temp->next;
       free(temp);
    }
    return *head;
}
//******************************* doubly delete after *****************************************
struct node * dll_DeleteAfter(struct node **head,int loc){
    if(*head==NULL){
       printf("List is empty");
    }else{
        temp = *head;
        while(temp->data != loc)
            temp = temp->next;

        temp1=temp->next;
        temp->next=temp1->next;
        temp1->next->prev=temp;

        free(temp1);
    }
    return *head;
}
//******************************* doubly delete end  ******************************************
struct node * dll_DeleteEnd(struct node **head){
    if(*head==NULL){
       printf("List is empty");
       free(*head);
    }else{
        temp = *head;
        while(temp->next !=NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
    return *head;
}
//******************************* doubly delete first *****************************************
// not working
struct node * dll_DeleteFirst(struct node *head)
{
    if(head==NULL){
       printf("List is empty");
    }
    else if(head->next == NULL){
        head=NULL;
        free(head);
        printf("node deleted");
    }
    else{
        temp = head;
        head = temp->next;
        temp->prev = NULL;
        free(temp);
    }
    return head;
}
//******************************* display_Dcl **************************************************
void display_Dcl(struct node **head){
    temp = *head;

         while(temp->next != NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
         }
         printf("%d",temp->data);   
}
