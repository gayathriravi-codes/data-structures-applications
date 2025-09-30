#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 10
struct stack
{
    int top;
    char data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s,char letter)
{
    s->data[++(s->top)]=letter;
}
char pop(STACK *s)
{
    return s->data[(s->top)--];
}
char ispalindrome(STACK *s,char str[])
{
    int i,len;
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        push(s,str[i]);
    }
    for(i=0;i<len;i++)
    {
        if(str[i]!=pop(s))
            return 0;
    }
    return 1;
}
int main()
{
    char str[20];
    STACK s;
    s.top=-1;
    printf("\nRead the string:\n");
    scanf("%s",&str);
    if(ispalindrome(&s,str))
        printf("The given string is palindrome");
    else
        printf("The given string is not a palindrome");
    return 0;
}
