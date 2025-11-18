#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int count;
struct node
{
    int data;
    struct node *addr;
};
typedef struct node *NODE;
NODE push(NODE start,int item)
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    if(count>=SIZE)
    {
        printf("\nStack Overflow");
        return start;
    }
    temp->data=item;
    temp->addr=start;
    count+=1;
    return temp;
}

NODE pop(NODE start)
{
    NODE temp;
    if(start==NULL)
    {
        printf("\nStack Underflow");
        return NULL;
    }
    temp=start;
    start=start->addr;
    printf("\nElement popped is %d",temp->data);
    free(temp);
    count-=1;
    return start;
}

void display(NODE start)
{
    NODE temp;
    if(start==NULL)
        printf("\nStack is empty");
    else
    {
        printf("\nStack Content - \n");
        temp=start;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->addr;
        }
    }
}

int main()
{
    NODE start=NULL;
    int ch,item;
    for(;;)
    {
        printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT");
        printf("\nRead choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nRead the element to be inserted: ");
                    scanf("%d",&item);
                    start=push(start,item);
                    break;
            case 2: start=pop(start);
                    break;
            case 3: display(start);
                    break;
            default: exit(0);
        }
    }
    return 0;
}
