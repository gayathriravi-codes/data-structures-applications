#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

NODE createBST(NODE root,int key)
{
    NODE temp,cur,prev;
    temp=(NODE)malloc(sizeof(struct node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
        return temp;
    cur=root;
    prev=NULL;
    while(cur!=NULL)
    {
        prev=cur;
        if(key < cur->data)
            cur=cur->left;
        else
            cur=cur->right;
    }
    if(key < prev->data)
        prev->left=temp;
    else
        prev->right=temp;
    return root;
}

void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

NODE inorder_successor(NODE root)
{
    NODE cur;
    cur=root;
    while(cur->left!=NULL)
        cur=cur->left;
    return cur;
}

NODE delete_node(NODE root,int key)
{
    NODE temp;
    if(root==NULL)
        return NULL;
    if(key < root->data)
        root->left=delete_node(root->left,key);
    else if(key > root->data)
        root->right=delete_node(root->right,key);
    else
    {
        if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        temp=inorder_successor(root->right);
        root->data=temp->data;
        root->right=delete_node(root->right,temp->data);
    }
    return root;
}

int main()
{
    NODE root=NULL;
    int item,ch;
    for(;;)
    {
        printf("\n1.INSERT\n2.PREORDER\n3.INORDER\n4.POSTORDER\n5.DELETE\n6.EXIT");
        printf("\nRead choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nRead the item to be inserted: ");
                    scanf("%d",&item);
                    root=createBST(root,item);
                    break;
            case 2: printf("\nThe Preorder Traversal is - \n");
                    preorder(root);
                    break;
            case 3: printf("\nThe Inorder Traversal is - \n");
                    inorder(root);
                    break;
            case 4: printf("\nThe Postorder Traversal is - \n");
                    postorder(root);
                    break;
            case 5: printf("\nEnter the item to delete: ");
                    scanf("%d", &item);
                    root = delete_node(root, item);
                    printf("\nNode deleted successfully.\n");
                    break;
            default: exit(0);
        }
    }
    return 0;
}
