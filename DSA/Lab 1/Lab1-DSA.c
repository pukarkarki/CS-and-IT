#include <stdio.h>
#define MAX 10
#define true 1
#define false 0
struct Stack
{
    int data[MAX];
    int TOP;
};
void PUSH(struct Stack *S, int ele);
int POP(struct Stack *S);
int PEEK(struct Stack *S);
int isFULL(struct Stack *S);
int isEMPTY(struct Stack *S);
int main()
{
    int choice,ele;
    struct Stack SS;
    SS.TOP = -1;
    do
    {
    printf("\n1.PUSH\n2.POP\n3.PEEK\n4.EXIT\n");
    printf("Enter your choice ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter Element: ");
        scanf("%d", &ele);
        PUSH(&SS,ele);
        break;

    case 2:
        if (isEMPTY(&SS))
        {
            printf("STACK UNDERFLOW\n");
        }
        else
        {
            ele = POP(&SS);
            printf("%d was POPPED",ele);
        }
        break;

    case 3:
        if (isEMPTY(&SS))
        {
            printf("STACK EMPTY\n");
        }
        else
        {
            ele = PEEK(&SS);
            printf("%d was at TOP\n",ele);
        }
        break;

    case 4:
        printf("BYE\n");
        break;

    default:
        printf("Enter 1, 2, 3 or 4 only");
        break;
    }
    }while(choice != 4);
    return 0;
}

void PUSH(struct Stack *S, int ele)
{
    if(isFULL(S))
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        S->TOP += 1;
        S->data[S->TOP] = ele;
        printf("%d was PUSHED\n",ele);
    }

}
int POP(struct Stack *S)
{
    int ret = S->data[S->TOP];
    S->TOP -= 1;
    return ret;
}
int PEEK(struct Stack *S)
{
    return S->data[S->TOP];
}
int isFULL(struct Stack *S)
{
    /*
    if (S->TOP == MAX -1)
        return true;
    else
        return false;
    */
    return S->TOP == MAX -1 ? true : false;
}
int isEMPTY(struct Stack *S)
{
    /*
    if(S->TOP == -1)
        return true;
    else
        return false;
    */
    return S->TOP == -1 ? true : false;
}




