Topic : Doubly LinkedList

Description : Doubly linked list is a complex type of linked list in which a node contains a pointer to the previous as well as the next node in the sequence.

1.Insert element at begining in doubly linked list:
struct node * dll_InsertBegin(struct node **head, int val)
It takes two arguments
1) head node of struct type 
2) value / data to be inserted

2.Insert element at end in doubly linked list:
struct node * dll_InsertEnd(struct node **head,int val)
It takes two arguments
1) head node of struct type 
2) value / data to be inserted
this function is used to  insert the element at end 


3.Insert at location in doubly linked list :
struct node * dll_InsertAtLocation(struct node **head,int val,int loc)
It takes Three arguments
1) head node of struct type 
2) value / data to be inserted
3)location (data value after which you want to insert)
this function is used to  insert the element at location.

4.Insert element before specific element in doubly linked list:
struct node * dll_InsertBefore(struct node **head,int val,int loc)
It takes Three arguments
1) head node of struct type 
2) value / data to be inserted
3)location (data value after which you want to insert)


5.Insert element after specific element:
struct node * dll_InsertAfter(struct node **head,int val,int loc)
It takes Three arguments
1) head node of struct type 
2) value / data to be inserted
3)location (data value after which you want to insert)


6.delete  at location in doubly linked list :
struct node * dll_DeleteAtLocation(struct node **head,int loc)
It takes two arguments
1) head node of struct type 
2)location (data value after which you want to insert)


7.delete before  a node in doubly linked list:
struct node * dll_DeleteBefore(struct node **head,int loc)
It takes two arguments :
1) head node of struct type 
2)location (data value after which you want to insert)



8.delete after  a node in doubly linked list :
struct node * dll_DeleteAfter(struct node **head,int loc)
It takes two arguments :
1) head node of struct type 
2)location (data value after which you want to insert)



9.delete last element in doubly linked list:
struct node* dll_DeleteEnd(struct node **head)
It takes one argument :
1.head node of struct type


7.delete first element in doubly linked list :
struct node * dll_DeleteFirst(struct node **head)
It takes one argument
1.head node of struct type


10.Display element in doubly linked list:
void display_dcl(struct node *head)
It takes one argument
1.head node of struct type



