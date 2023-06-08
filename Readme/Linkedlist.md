Topic : LinkedList

Description :A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers.

1.Insert element at begining in singly linked list :
struct node * ssl_InsertBegin(struct node **head, int val)
It takes two arguments
1) head node of struct type 
2) value / data to be inserted

2.Insert element at end in singly linked list :
struct node * ssl_InsertEnd(struct node **head,int val)
It takes two arguments
1) head node of struct type 
2) value / data to be inserted


3.Insert element after specific element in singly linked list :
struct node * ssl_InsertAfter(struct node **head,int val,int loc)
It takes Three arguments
1) head node of struct type 
2) value / data to be inserted
3)location (data value after which you want to insert)


4.Insert element before specific elementin singly linked list:
struct node * ssl_InsertBefore(struct node **head,int val,int loc)
It takes Three arguments
1) head node of struct type 
2) value / data to be inserted
3)location (data value after which you want to insert)


5.Insert at location in singly linked list:
struct node * ssl_InsertAtLocation(struct node **head,int val,int loc)
It takes Three arguments
1) head node of struct type 
2) value / data to be inserted
3)location (data value after which you want to insert)


6.Display element  in Singly linked list :
void display_Ssl(struct node *head)
It takes one argument
1.head node of struct type


7.delete first element  in Singly linked list:
struct node * ssl_DeleteFirst(struct node **head)
It takes one argument
1.head node of struct type


8.delete last element in singly linked list 
struct node* ssl_DeleteEnd(struct node **head)
It takes one argument :
1.head node of struct type


9.delete after a node in Singly linked list :
struct node * ssl_DeleteAfter(struct node **head,int loc)
It takes two arguments
1) head node of struct type 
2)location (data value after which you want to insert)


9.delete before a node in Singly linked list:
struct node * ssl_DeleteBefore(struct node **head,int loc)
It takes two arguments
1) head node of struct type 
2)location (data value after which you want to insert)


10.delete  at location :
struct node * ssl_DeleteAtLocation(struct node **head,int loc)
It takes two arguments
1) head node of struct type 
2)location (data value after which you want to insert)





