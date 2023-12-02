#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node *insert(struct node *root ,int data)
{
    if(root == NULL)
    return createnode(data);
    else
    {
        if(data < root->data)
        root->left = insert(root->left, data);
        else
        root->right = insert(root->right, data);

    }
    return root;
}

void inorder(struct node *root)
{
    if(root == NULL)
    return;
    else
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void preorder(struct node *root)
{
    if(root == NULL)
    return;
    else
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root == NULL)
    return;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}





int main()
{
    struct node *root = NULL;

   root =  insert(root , 50);
   root =  insert(root , 10);
   root =  insert(root , 100);
   root =  insert(root , 20);
   root =  insert(root , 90);
  root =   insert(root , 30);
  root =   insert(root , 70);
  root =   insert(root , 40);

    printf("the binary tree are traverse in inorder wise:");
    inorder(root);
    printf("\n");
    printf("the binary tree are traverse in preorder wise:");
    preorder(root);
    printf("\n");
    printf("the binary tree are traverse in postorder wise:");
    postorder(root);
    printf("\n");


 

    return 0;
}
