Topic : Tree

Description :
	A Tree is a non-linear data structure and a hierarchy consisting of a collection of nodes such that each node of the tree stores a value and a list of references to other nodes 

1.Inorder traversal :
     void inorderTraversal(struct node* root)
      it passes the root node which is of struct type .  
     Algorithm :
    1.  Traverse the left subtree, i.e., call Inorder(left->subtree)
    2. Visit the root.
    3. Traverse the right subtree, i.e., call Inorder(right->subtree)
  
2.preorderTraversal traversal
     void preorderTraversal(struct node* root)
     it passes the root node which is of struct type .  
     Algorithm :
    1.Visit the root.
    2.Traverse the left subtree, i.e., call Preorder(left->subtree)
     3. Traverse the right subtree, i.e., call Preorder(right->subtree) 

3.postorderTraversal traversal
   void postorderTraversal(struct node* root) 
   it passes the root node which is of struct type .  
  Algorithm :
  1. Traverse the left subtree, i.e., call Postorder(left->subtree)
  2.Traverse the right subtree, i.e., call Postorder(right->subtree)
  3.Visit the root

4.Create a new Node
 struct node* Tree_Createnode(int value)
 it passes the value type integer.
it used to create node .

5.Tree_InsertLeft :
struct node* Tree_InsertLeft(struct node* root, int value)
  it passes the root node which is of struct type and value type integer .

6.Tree_InsertRight
struct node* Tree_InsertRight(struct node* root, int value)
  it passes the root node which is of struct type and value type integer .

7.search :
char Tree_Search(struct node* root, int value) 
  it passes the root node which is of struct type and value type integer .
it used to search element in tree 

8.Depth of tree
int Tree_MaxDepth(struct node* root)
  it passes the root node which is of struct type
it used to calculate height of the tree

9.create new node 
struct node *newNode(int data)
  it passes the integer data which is of struct type
 it used to create new node 

10.Binary Search Tree Insert 
struct node *Tree_BinaryInsert(struct node *node, int key)
 it passes the root node which is of struct type and key type integer .
it used to insert the element in binary  search tree 

11.binary search tree 
struct node* Tree_BinarySearch(struct node* root,int data)
 it passes the root node which is of struct type and data type integer .


 
  
