#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct queue
{
    int r,f;
    int data[SIZE];
};
typedef struct queue QUEUE;
void cq_enqueue(QUEUE *q,int item)
{
    if(q->f==(q->r+1)%SIZE)
        printf("\nQueue is full");
    else
    {
        q->r=(q->r+1)%SIZE;
        q->data[q->r]=item;
        if(q->f==-1)
            q->f=0;
    }
}
void cq_dequeue(QUEUE *q)
{
    if(q->f==-1)
        printf("\nQueue is empty");
    else
    {
        printf("\nElement deleted is %d",q->data[q->f]);
        if(q->f==q->r)
        {
            q->f=-1;
            q->r=-1;
        }
        else
            q->f=(q->f+1)%SIZE;
    }
}
void display(QUEUE q)
{
    int i;
    if(q.f==-1)
        printf("\nQueue is empty");
    else
    {
        printf("\nQueue Content - \n");
        for(i=q.f;i!=q.r;i=(i+1)%SIZE)
            printf("%d\t",q.data[i]);
        printf("%d",q.data[i]);
    }
}
int main()
{
    int ch,item;
    QUEUE q;
    q.f=-1;
    q.r=-1;
    for(;;)
    {
        printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT");
        printf("\nRead choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nRead the element to be inserted: ");
                    scanf("%d",&item);
                    cq_enqueue(&q,item);
                    break;
            case 2: cq_dequeue(&q);
                    break;
            case 3: display(q);
                    break;
            default: exit(0);
        }
    }
    return 0;
}
