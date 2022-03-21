#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int info;
    struct SLL *next;
};
typedef struct SLL NodeType;
NodeType *top;
void push(NodeType *S,int element);
int pop(NodeType *S);
int peek(NodeType *S);
int main()
{
    int choice,element;
    NodeType Stack;
    top = NULL;
    do
    {
        printf("1.PUSH\n2.POP\n3.PEEK\n4.EXIT\n");
        printf("Your choice? ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter element : ");
                scanf("%d",&element);
                push(&Stack,element);
                break;

            case 2:
                if(top == NULL)
                    printf("STACK UNDERFLOW\n");
                else
                {
                    printf("%d WAS POPPED\n",pop(&Stack));
                }
                break;

            case 3:
                if(top == NULL)
                    printf("STACK IS EMPTY\n");
                else
                {
                    printf("%d IS AT TOP\n",peek(&Stack));
                }
                break;

            case 4:
                printf("BYE\n");
        }
    } while (choice != 4);
    return 0;
}

void push(NodeType *S,int element)
{
    NodeType *NewNode;
    NewNode = (NodeType*)malloc(sizeof(NodeType));
    if(NewNode == NULL)
        printf("MEMORY ALLOCATION FAILED\n");
    else
    {
        NewNode->info = element;
        NewNode->next = NULL;
        //Case 1: Stack is Empty i.e top == NULL
        if(top == NULL)
            top = NewNode;
        else
        {
        //Case 2: Stack is not empty
            NewNode->next = top;
            top = NewNode;    
        }
        printf("%d was successfully PUSHED\n",top->info);
    }
}
int pop(NodeType *S)
{
    NodeType *temp;
    int ret= top->info;
    //Case 1: When there is only a single element on stack
    if(top->next == NULL)
    {
        temp = top;
        free(temp);
        top = NULL;
    }
    else
    {
    //Case 2: When there are multiple elements in the stack
        temp = top;
        top = top->next;
        free(temp);    
    }
    return ret;
}
int peek(NodeType *S)
{
    return top->info;
}









