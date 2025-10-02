#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct stack
{
    int top;
    char data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s,char item)
{
    s->data[++(s->top)]=item;
}
char pop(STACK *s)
{
    return s->data[(s->top)--];
}
void parantheses_checker(STACK *s,char brac[20])
{
    int i;
    char symbol,element;
    for(i=0;brac[i]!='\0';i++)
    {
        symbol=brac[i];
        if(symbol=='(' || symbol=='{' || symbol=='[')
            push(s,symbol);
        else if (symbol==')' || symbol=='}' || symbol==']')
        {
            if(s->top==-1)
            {
                printf("\nInvalid, stack is empty!");
                return;
            }
            element=pop(s);
            if((symbol=='(' && element!=')') || (symbol=='{' && element!='}') || (symbol=='[' && element!=']'))
            {
                printf("\nInvalid brackets");
                return;
            }
        }

    }
    if(s->top==-1)
        printf("\nValid parantheses");
    else
        printf("\nInvalid parantheses");
}
int main()
{
    char brac[20];
    STACK s;
    s.top=-1;
    printf("\nRead the brackets: ");
    scanf("%s",brac);
    parantheses_checker(&s,brac);
    return 0;
}
