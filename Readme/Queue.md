Topic : Queue

Description : A Queue is defined as a linear data structure that is open at both ends and the operations are performed in First In First Out (FIFO) order.

1.create Singley Ended Queue
void create_SEQ(int *front, int *rear)
it takes two arguments:
1.pointer front type integer.
2.pointer rear type integer .
it used to create Singley Ended Queue.

2.Insert elment in Singley Ended Queue
void insert_SEQ(int *q,int *rear, int element)
it takes three arguments:
1.pointer q type integer.
2.pointer rear type integer .
3.element to be inserted .
it used to insert element in Singley Ended Queue.

3.delete elment in Singley Ended Queue
int delete_SEQ(int *q,int *front)
it takes two arguments:
1.pointer q type integer.
2.pointer front type integer .
it used to delete  elment in Singley Ended Queue

4.isfull() :
int isFull_SEQ(int rear,int size)
it takes two arguments:
1. rear  type integer.
2.size of queue
Checks if the queue is full.

5.isempty()
int isEmpty_SEQ(int front, int rear)
it takes two arguments:
1. front type integer.
2.rear  type integer.
Checks if the queue is empty.

6. Display():
void display_SEQ(int *q,int front,int rear)
it takes three arguments:
1.pointer q type integer.
2. rear type integer .
3. front type integer.
it used to display Singley Ended Queue.

7.create double Ended Queue
void create_DEQ(struct dequeue *block)
it take one argument:
1.block dequeue of struct type 
it used to create double Ended Queue.

8.isempty()
int isEmpty_DEQ(struct dequeue *block)
it take one argument:
1.block dequeue of struct type 
Checks if the queue is empty.

9.isfull() :
int isFull_DEQ(struct dequeue *block)
it take one argument:
1.block dequeue of struct type 
Checks if the queue is full.

10.insertFront()
void insertFront_DEQ(struct dequeue *block,int data)
it takes two arguments:
1.block dequeue of struct type 
2.data or element to be inserted
it used to Adds an item at the front of Deque.

11.insertRear():
void insertRear_DEQ(struct dequeue *block,int data)
it takes two arguments:
1.block dequeue of struct type 
2.data or element to be inserted
it used to Adds an item at the rear of Deque.

12.deleteFront():
int deleteFront_DEQ(struct dequeue *block)
it take one argument:
1.block dequeue of struct type 
it used to  Deletes an item from the front of Deque.

13.deleteRear():
int deleteRear_DEQ(struct dequeue *block)
it take one argument:
1.block dequeue of struct type 
it used to  Deletes an item from the rear of Deque. 

14.Display()
void display_DEQ(struct dequeue *block)
it take one argument:
1.block dequeue of struct type 
it used to display the Deque.


15.enQueue(value):
void insert_CQ(int item)
it take one argument:
1.item to be inserted .
This function is used to insert an element into the circular queue. In a circular queue, the new element is always inserted at Rear position. 


16.deQueue():
int delete_CQ()
 This function is used to delete an element from the circular queue. In a circular queue, the element is always deleted from front position. 


17.isEmpty():
int isEmpty_CQ()
this function is used to Checks if the queue is empty.

18.dispaly():
void display_CQ()
this function is used to display circular queue.
 









