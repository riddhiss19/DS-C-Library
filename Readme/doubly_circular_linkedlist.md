Topic : doubly circular LinkedList

Description : Circular doubly linked list is a more complexed type of data structure in which a node contain pointers to its previous node as well as the next node.

1.Insert element at begining when linked list is empty in doubly circular LinkedList  :
struct node* dcl_AddANode(int val)
It takes one argument
1) value / data to be inserted


2.Insert element at begining in doubly circular LinkedList :
struct node * dcl_InsertBegin(struct node **tail, int val)
It takes two arguments
1) tail node of struct type 
2) value / data to be inserted

3.Insert element at end in doubly circular LinkedList:
struct node * dcl_InsertEnd(struct node *tail,int val)
It takes two arguments
1) tail node of struct type 
2) value / data to be inserted


4.Insert element before specific element in doubly circular LinkedList:
struct node * dcl_InsertBefore(struct node *tail ,int val,int loc)
It takes Three arguments
1) tail node of struct type 
2) value / data to be inserted
3)location (data value after which you want to insert)

5.Insert element after specific element in doubly circular LinkedList:
struct node * dcl_InsertAfter(struct node **tail,int val,int loc)
It takes Three arguments
1) tail node of struct type 
2) value / data to be inserted
3)location (data value after which you want to insert)

6.Insert at location in doubly circular LinkedList:
struct node * dcl_InsertLocation(struct node *tail,int val,int loc)
It takes Three arguments
1) tail node of struct type 
2) value / data to be inserted
3)location (data value after which you want to insert)

7.delete begin element in doubly circular LinkedList :
struct node * dcl_DeleteBegin(struct node *tail)
It takes one argument:
1.tail node of struct type

9.delete last element in doubly circular LinkedList:
struct node* dcl_DeleteEnd(struct node *tail)
It takes one argument :
1.tail  node of struct type

8.delete before a node  in doubly circular LinkedList:
struct node * dcl_DeleteBefore(struct node *tail,int loc)
It takes two arguments :
1) tail node of struct type 
2)location (data value after which you want to insert)

9.delete after a node  in doubly circular LinkedList:
struct node * dcl_DeleteAfter(struct node *tail,int loc)
It takes two arguments :
1) tail node of struct type 
2)location (data value after which you want to insert)

10.delete  at location in doubly circular LinkedList :
struct node * dcl_DeleteAtLocation(struct node *tail,int loc)
It takes two arguments
1) tail node of struct type 
2)location (data value after which you want to insert)

11.Display element in doubly circular LinkedList :
void display_dcl(struct node *tail)
It takes one argument
1.tail node of struct type
