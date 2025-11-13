#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *addr;
};
typedef struct node *NODE;
NODE ordered_list(NODE start,int item)
{
    NODE temp,cur,prev;
    temp=(NODE)malloc(sizeof(struct node));
    temp->data=item;
    temp->addr=NULL;
    if(start==NULL)
        return temp;
    if(item<=start->data)
    {
        temp->addr=start;
        return temp;
    }
    prev=NULL;
    cur=start;
    while(cur!=NULL && item>cur->data)
    {
        prev=cur;
        cur=cur->addr;
    }
    prev->addr=temp;
    temp->addr=cur;
    return start;
}
void display(NODE start)
{
    NODE cur=start;
    if(cur == NULL)
    {
        printf("\nList is empty");
        return;
    }
    printf("\nOrdered List: ");
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
    printf("\nRead the number of elements to insert: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nRead element %d: ",i+1);
        scanf("%d",&item);
        start=ordered_list(start,item);
    }
    display(start);
    return 0;
}
