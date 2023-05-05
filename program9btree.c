#include<stdio.h>
#include<stdlib.h>

struct btreenode
{
    struct btreenode* leftchild;
    int data;
    struct btreenode* rightchild;
};
    void insert(struct btreenode**,int);
    void inorder(struct btreenode*);
    void preorder(struct btreenode*);
    void postorder(struct btreenode*);
    void main()
    {
    struct btreenode *bt;
        int req;
        int i=0,num;
        bt = NULL;
        printf("Enter the number of items to be inserted:");
        scanf("%d",&req);
        while(i<req)
        {
        printf("Enter the data: ");
        scanf("%d",&num);
        insert(&bt,num);
        i++;
        }
    printf("\nInorder Traversal : ");
    inorder(bt);
    printf("\nPreorder Traversal : ");
    preorder(bt);
    printf("\nPostorder Traversal : ");
    postorder(bt);
    }

    void insert(struct btreenode **root, int num)

    {
    if(*root == NULL)
    {
    *root = malloc(sizeof(struct btreenode));
    (*root)->leftchild = NULL;
    (*root)->data = num;
    (*root)->rightchild=NULL;
    return;
    }
    else
    {
    if(num<(*root)->data)
        insert(&((*root)->leftchild),num);
        else
        insert(&((*root)->rightchild),num);
    }
    }

    void inorder(struct btreenode* root)

    {
 if(root != NULL)
 {
 inorder(root ->leftchild);
 printf("\t %d",root->data);
 inorder(root ->rightchild);
 }
}
void preorder(struct btreenode* root)
{
 if(root != NULL)
 {
 printf("\t %d",root->data);
 preorder(root ->leftchild);
 preorder(root ->rightchild);
 }
}
void postorder(struct btreenode* root)
{
 if(root != NULL)
 {
 postorder(root ->leftchild);
 postorder(root ->rightchild);
 printf("\t %d",root->data);
 }
}
