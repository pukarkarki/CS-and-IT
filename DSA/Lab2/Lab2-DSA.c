#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
struct Stack
{
    char data[MAX];
    int TOP;
};
void push(struct Stack *S, char element)
{
    S->data[++S->TOP] = element;
}
char pop(struct Stack *S)
{
    return S->data[S->TOP--];
}
int priority(char operator)
{
    if (operator == '^')
        return 3;
    if(operator == '/' || operator == '*')
        return 2;
    if(operator == '+' || operator == '-')
        return 1; 
    if(operator == '(')
        return 0;
}
int main()
{
    struct Stack SS;
    SS.TOP = -1;
    char infix[MAX], postfix[MAX],aVar;
    printf("ENTER INFIX: ");
    gets(infix);
    int i=0,j=0;
    while(infix[i] != '\0')
    {
        switch(infix[i])
        {
            case '(':
                push(&SS, infix[i]);
                break;

            case ')':
                aVar = pop(&SS);
                while(aVar != '(')
                {
                    postfix[j++] = aVar;
                    aVar = pop(&SS);
                }
                break;
            
            case '^':
            case '/':
            case '*':
            case '+':
            case '-':
                if (SS.TOP == -1)
                    push(&SS, infix[i]);
                else if (priority(infix[i]) > priority(SS.data[SS.TOP]))
                    push(&SS,infix[i]);
                else
                {
                    while(priority(infix[i]) <= priority(SS.data[SS.TOP]))
                    {
                        aVar = pop(&SS);
                        postfix[j++] = aVar;
                    }
                    push(&SS,infix[i]);
                }
                break;

            default:
                postfix[j++] = infix[i];
                break;
        }
        i++;
    }
    while(SS.TOP != -1)
    {
        postfix[j++] = pop(&SS);
    }
    printf("The POSTFIX expression is %s\n",postfix);
    return 0;
}