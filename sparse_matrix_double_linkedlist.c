#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row,col,data;
    struct node *next;
    struct node *prev;
};
typedef struct node * NODE;

NODE insert_end(NODE start,int row,int col,int item)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->row=row;
    temp->col=col;
    temp->data=item;
    temp->next=NULL;
    temp->prev=NULL;
    if(start==NULL)
        return temp;
    cur=start;
    while(cur->next!=NULL)
        cur=cur->next;
    cur->next=temp;
    temp->prev=cur;
    return start;
}
void display(NODE start)
{
    NODE temp;
    if(start==NULL)
        printf("\nThe list is empty");
    else
    {
        printf("\nROW\tCOL\tDATA\n");
        temp=start;
        while(temp!=NULL)
        {
            printf("%d\t%d\t%d\n",temp->row,temp->col,temp->data);
            temp=temp->next;
        }
    }
}
void display_matrix(NODE start,int m,int n)
{
    NODE temp=start;
    int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(temp!=NULL && temp->row==i && temp->col==j)
            {
                printf("%d\t",temp->data);
                temp=temp->next;
        }
    else
        printf("0\t");
}
printf("\n");
    }
}
int main()
{
    int i,j,m,n,item;
    NODE start=NULL;
    printf("\nRead the order of matrix: ");
    scanf("%d%d",&m,&n);
    printf("\nRead the elements - \n");
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&item);
            if(item!=0)
                start=insert_end(start,i,j,item);
        }
    }
    display(start);
    printf("\nSparse Matrix is - \n");
    display_matrix(start,m,n);
    return 0;
}
