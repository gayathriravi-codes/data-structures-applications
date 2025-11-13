#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *addr;
};
typedef struct node *NODE;
NODE insert_end(NODE start,int item)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->data=item;
    temp->addr=NULL;
    if(start==NULL)
        return temp;
    cur=start;
    while(cur->addr!=NULL)
        cur=cur->addr;
    cur->addr=temp;
    return start;
}
NODE reverse_list(NODE start)
{
    NODE temp,cur,prev;
    if(start->addr==NULL)
        return start;
    temp=NULL;
    prev=NULL;
    cur=start;
    while(cur!=NULL)
    {
        temp=prev;
        prev=cur;
        cur=cur->addr;
        prev->addr=temp;
    }
    return prev;
}
void display(NODE start)
{
    NODE cur=start;
    if(cur == NULL)
    {
        printf("\nList is empty");
        return;
    }
    while(cur!=NULL)
    {
        printf("%d\t",cur->data);
        cur=cur->addr;
    }
}
int main()
{
    NODE start=NULL;
    int n,item,i;
    printf("\nRead the number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nRead element %d: ",i+1);
        scanf("%d",&item);
        start=insert_end(start,item);
    }
    printf("\nOriginal List - \n");
    display(start);
    start=reverse_list(start);
    printf("\nReversed List -\n");
    display(start);
    return 0;
}
