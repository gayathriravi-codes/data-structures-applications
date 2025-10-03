#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct stack
{
    int top;
    int data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s,int rem)
{
    s->data[++(s->top)]=rem;
}
int pop(STACK *s)
{
    return s->data[(s->top)--];
}
void int_to_bin(STACK *s,int num)
{
    int temp=num,rem,bin[10],i=0,j=0;
    while(num!=0)
    {
        rem=num%2;
        push(s,rem);
        num=num/2;
    }
    while(s->top!=-1)
    {
        bin[i++]=pop(s);
    }
    printf("\nThe binary equivalent of %d is: ",num);
    for(j=0;j<i;j++)
        printf("%d",bin[j]);
}
int main()
{
    int num;
    STACK s;
    s.top=-1;
    printf("\nRead the integer:\n");
    scanf("%d",&num);
    int_to_bin(&s,num);
    return 0;
}
