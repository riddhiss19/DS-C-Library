#ifndef TREE
#define TREE

#include <stdio.h>
#include <stdlib.h>



struct node {
  int item;
  struct node* left;
  struct node* right;
}*root =NULL,
*temp=NULL;
                                                                             
int Tree_MaxDepth(struct node *root);
void inorderTraversal(struct node* root);
void preorderTraversal(struct node* root);
void postorderTraversal(struct node* root);
int Tree_LevelWise(struct node* root);

struct node* Tree_Createnode(int value);
struct node* Tree_InsertLeft(struct node* root, int value);
struct node* Tree_InsertRight(struct node* root, int value);
char Tree_Search(struct node* root, int value) ;

struct node *newNode(int data);
struct node *Tree_BinaryInsert(struct node *node, int key) ;
struct node* Tree_BinarySearch(struct node* root,int data);
struct node* Tree_BinaryDelete(struct node* root, int key);

int Tree_LeafNode(struct node *root);
void Tree_mirror(struct node* root);
void calling(struct node * root, int temp);
struct node* minValueNode(struct node* node);

int success=1;
int Tree_MaxDepth(struct node* root)
{
    if (root== NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = Tree_MaxDepth(root->left);
        int rDepth = Tree_MaxDepth(root->right);
        int flag;
  
        /* use the larger one */
        if (lDepth > rDepth){
            // printf("\n Dept is :- %d",lDepth+1);
            flag=0;
            return (lDepth + 1);}
        else{
            // printf("\n Dept is :- %d",rDepth+1);
            flag=1;
            return (rDepth + 1);}

    }
}
// Inorder traversal
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}

// preorderTraversal traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// postorderTraversal traversal
void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}

int Tree_LevelWise(struct node* root)
{
   int depth = Tree_MaxDepth(root);
   printf("\n\nLevelWise Display Of Tree :- \n");
   for (int i = 1; i <= depth; i++)
        calling(root, i);
}
void calling(struct node * root, int temp)
{
   
   if (root == NULL)
        return;
    if (temp == 1)
        printf("%d -->", root->item);
    else if (temp > 1) {
        calling(root->left, temp - 1);
        calling(root->right, temp - 1);
    }
  
}



/////////////////////////     SIMPLE BINARY TREE        //////////////////////////////////


// Create a new Node
struct node* Tree_Createnode(int value)
 {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;
  
  return newNode;
}

// Insert on the left of the node
struct node* Tree_InsertLeft(struct node* root, int value) {
  root->left = Tree_Createnode(value);
  return root->left;
}

// Insert on the right of the node
struct node* Tree_InsertRight(struct node* root, int value) {
  root->right = Tree_Createnode(value);
  return root->right;
}

char Tree_Search(struct node* root, int value) 
{ 
    // while is used to traverse till the end of tree
    while (root != NULL){

        // checking condition and passing right subtree & recusing 
        if (value > root->item) 
            root = root->right; 

        // checking condition and passing left subtree & recusing 
        else if (value < root->item) 
            root = root->left; 
        else
           printf( "\n\n Element Found") ;// if the value is found return 1 
    } 
    
}


/////////////////////////////For Binary Search Tree///////////////////////////////////


struct node *newNode(int data) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->item = data;
  temp->left = temp->right = NULL;
  return temp;
}

struct node *Tree_BinaryInsert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) 
   return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->item)
    node->left = Tree_BinaryInsert(node->left, key);
  else
    node->right = Tree_BinaryInsert(node->right, key);

  return node;
}

struct node* Tree_BinarySearch(struct node* root,int data){
   struct node *current = root;
   printf("\nVisiting elements: \n");
	
   while(current->item != data){
	
      if(current != NULL) {
         printf("%d ",current->item);
			
         //go to left tree
         if(current->item > data){
            current = current->left;
         }//else go to right tree
         else {                
            current = current->right;
         }
			
         //not found
         if(current == NULL){
            return 0;
         }
      }			
   }
   return current;
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
        
    return current;
}

struct node* Tree_BinaryDelete(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->item)
        root->left = Tree_BinaryDelete(root->left, key);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->item)
        root->right = Tree_BinaryDelete(root->right, key);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
         
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
        
        // Copy the inorder
        // successor's content to this node
        root->item = temp->item;
        
        // Delete the inorder successor
        root->right = Tree_BinaryDelete(root->right, temp->item);
    }
    return root;
}

////////////////////////// common Code ////////////////////////////////////

int Tree_LeafNode(struct node *root)
{
    /* Empty(NULL) Tree */
    if(root == NULL)
        return 0;
    /* Check for leaf node */
    if(root->left == NULL && root->right == NULL)
    {
        printf("%d -> ",root->item);
        return 1;
    }
    /* For internal nodes, return the sum of 
    leaf nodes in left and right sub-tree */
    return Tree_LeafNode(root->left) + Tree_LeafNode(root->right);
    
}

void Tree_mirror(struct node* root)
{
    if (root == NULL)
        return;
    else {
        struct node* temp;
        
        /* do the subtrees */
        Tree_mirror(root->left);
        Tree_mirror(root->right);
        
        /* swap the pointers in this node */
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

static int count = 0;
int Tree_countnodes(struct node *root)
{
    if(root != NULL)
    {
        Tree_countnodes(root->left);
        count++;
        Tree_countnodes(root->right);
    }
    return count;
}

int Tree_largestelement(struct node *root)
{  
    //Check whether tree is empty  
    temp = root;
    if(temp == NULL) 
    {  
        printf("Tree is empty\n");  
        return 0;  
    }  
    else{  
        int leftMax, rightMax;  
        int max = temp->item;  
        if(temp->left != NULL){  
            leftMax = Tree_largestelement(temp->left);   
            max = (max > leftMax) ? max : leftMax;  
        }  

        if(temp->right != NULL){  
          rightMax = Tree_largestelement(temp->right);  
          max = (max > rightMax) ? max : rightMax;  
        }  
    return max;  
    }  
}  
#endif