#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 20
struct stack
{
    int top;
    char data[SIZE];
};
typedef struct stack STACK;

void push(STACK *s, char item)
{
    s->data[++(s->top)] = item;
}

char pop(STACK *s)
{
    return s->data[(s->top)--];
}

int preced(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 5;
        default: return 0;
    }
}

void reverse_string(char str[])
{
    int i, j;
    char temp;
    for(i = 0, j = strlen(str)-1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infix_to_prefix(STACK *s, char infix[], int len)
{
    int i, j = 0;
    char symbol, prefix[20], temp;
    for(i = len-1; i >= 0; i--)
    {
        symbol = infix[i];
        if(isalnum(symbol))
        {
            prefix[j++] = symbol;
        }
        else
        {
            switch(symbol)
            {
                case ')': push(s, symbol);
                          break;
                case '(': temp = pop(s);
                          while(temp != ')')
                          {
                              prefix[j++] = temp;
                              temp = pop(s);
                          }
                          break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^': if(s->top == -1 || s->data[s->top] == ')')
                               push(s, symbol);
                          else
                          {
                              while(s->top != -1 && s->data[s->top] != ')' && preced(s->data[s->top]) > preced(symbol))
                              {
                                 prefix[j++] = pop(s);
                              }
                            push(s, symbol);
                          }
                          break;
            }
        }
    }
    while(s->top != -1)
    {
        prefix[j++] = pop(s);
    }
    prefix[j] = '\0';
    reverse_string(prefix);
    printf("\nPrefix expression is: %s\n", prefix);
}
int main() {
    int len;
    char infix[20];
    STACK s;
    s.top = -1;

    printf("Read infix expression:\n");
    scanf("%s", infix);

    len = strlen(infix);
    infix_to_prefix(&s, infix, len);

    return 0;
}
