Topic : singly circular LinkedList

Description : In a circular Singly linked list, the last node of the list contains a pointer to the first node of the list.

1.Insert element at begining when linked list is empty :
struct node* scl_AddANode(int val)
It takes one arguments
1) value / data to be inserted


2.Insert element at begining  in singly circular LinkedList :
struct node * scl_InsertBegin(struct node **tail, int val)
It takes two arguments
1) tail node of struct type 
2) value / data to be inserted


3.Insert element at end  in singly circular LinkedList:
struct node * scl_InsertEnd(struct node *tail,int val)
It takes two arguments
1) tail node of struct type 
2) value / data to be inserted



4.Insert at location  in singly circular LinkedList:
struct node * scl_InsertLocation(struct node *tail,int val,int loc)
It takes Three arguments
1) tail node of struct type 
2) value / data to be inserted
3)location(data value after which you want to insert)


5.Insert element before specific element:
struct node * scl_InsertBefore(struct node *tail ,int val,int loc)
It takes Three arguments
1) tail node of struct type 
2) value / data to be inserted
3)location


6.Insert element after specific element in singly circular LinkedList:
struct node * scl_InsertAfter(struct node **tail,int val,int loc)
It takes Three arguments
1) tail node of struct type 
2) value / data to be inserted
3)location(data value after which you want to insert)



7.delete after a node in singly circular LinkedList:
struct node * scl_DeleteAfter(struct node *tail,int loc)
It takes two arguments :
1) tail node of struct type 
2)location(data value after which you want to insert)



8.delete before a node in singly circular LinkedList:
struct node * scl_DeleteBefore(struct node *tail,int loc)
It takes two arguments :
1) tail node of struct type 
2)location(data value after which you want to insert)


9.delete last element in singly circular LinkedList:
struct node* scl_DeleteEnd(struct node *tail)
It takes one argument :
1.tail  node of struct type


10.delete first element  in singly circular LinkedList:
struct node * scl_DeleteFirst(struct node *tail)
It takes one arguments
1.tail node of struct type


11.delete  at location  in singly circular LinkedList:
struct node * scl_DeleteAtLocation(struct node *tail,int loc)
It takes two arguments
1) tail node of struct type 
2)location(data value after which you want to insert)


12.Display elememt  in singly circular LinkedList:
void display_scl(struct node *tail)
It takes one arguments
1.tail node of struct type
