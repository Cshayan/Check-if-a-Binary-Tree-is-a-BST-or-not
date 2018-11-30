#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top=-1;
int tempArr[MAX];
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
int Inorder(struct node *root)
{
    int i=0;
    struct node *stack[MAX];
    top=-1;
    while(top!=-1 || root!=NULL)
    {
        if(root!=NULL)
        {
            stack[++top]=root;
            root=root->left;
        }
        else
        {
            root=stack[top--];
            tempArr[i]=root->data;
            i++;
            root=root->right;
        }
    }
    int chk= checkAscending(tempArr, i);
    return chk;
}
int checkAscending(int tempArr[], int i)
{
    if(i==0 || i==1)
    {
        return 0;
    }
    int j;
    for(j=1; j<i; j++)
    {
       if(tempArr[j-1]>tempArr[j])
          return 0;
    }
    return 1;
}
struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
int main()
{
    struct node *root = newNode(3);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(4);

    if( Inorder(root) )
        printf("Is a BST\n");
    else
        printf("Not a BST\n");

    return 0;
}
