#include<stdio.h>
#include<stdlib.h>
#define bool int

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = height(node->left);
       int rDepth = height(node->right);

       /* use the larger one */
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
} 


bool isBalanced(struct node *root)
{
   int lh; /* for height of left subtree */
   int rh; /* for height of right subtree */   

   /* If tree is empty then return true */
   if(root == NULL)
    return 1; 

   /* Get the height of left and right sub trees */
   lh = height(root->left);
   rh = height(root->right);

   if( abs(lh-rh) <= 1 &&
       isBalanced(root->left) &&
       isBalanced(root->right))
     return 1;

   /* If we reach here then tree is not balanced */
   return 0;
}


/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                                malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

/* driver program to test above functions */
int main()
{
    struct node *root = newNode(8);
    root->left = newNode(6);
    root->right = newNode(9);
    root->left->left = newNode(5);
    root->left->right = newNode(7);
    root->right->right=newNode(10);
    root->left->left->left = newNode(4);

    if(isBalanced(root))
      printf("Tree is balanced");
    else
      printf("Tree is not balanced");    

    getchar();
    return 0;
}
