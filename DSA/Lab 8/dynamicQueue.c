#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int info;
    struct SLL *next;
};
typedef struct SLL NodeType;
NodeType *front,*rear;
void enqueue(NodeType *S,int element);
int dequeue(NodeType *S);
int checkF(NodeType *S);
int checkR(NodeType *S);
int main()
{
    int choice,element;
    NodeType Queue;
    front = NULL;
    rear = NULL;
    do
    {
        printf("1.ENQUEUE\n2.DEQUEUE\n3.CHECK F");
        printf("\n4.CHECK R\n5.EXIT\n");
        printf("Your choice? ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter element : ");
                scanf("%d",&element);
                enqueue(&Queue,element);
                break;

            case 2:
                if(front == NULL)
                    printf("QUEUE IS EMPTY\n");
                else
                {
                    printf("%d WAS DEQUEUED\n",dequeue(&Queue));
                }
                break;

            case 3:
                if(front == NULL)
                    printf("QUEUE IS EMPTY\n");
                else
                {
                    printf("%d IS AT FRONT\n",checkF(&Queue));
                }
                break;

            case 4:
                if(front == NULL)
                    printf("QUEUE IS EMPTY\n");
                else
                {
                    printf("%d IS AT REAR\n",checkR(&Queue));
                }
                break;

            case 5:
                printf("BYE\n");
        }
    } while (choice != 5);
    return 0;
}

void enqueue(NodeType *S,int element)
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
        if(front == NULL)
        {
            front = NewNode;
            rear = NewNode;
        }
        else
        {
        //Case 2: Stack is not empty
            rear->next = NewNode;
            rear = NewNode;   
        }
        printf("%d was successfully ENQUEUED\n",rear->info);
    }
}
int dequeue(NodeType *S)
{
    NodeType *temp;
    int ret= front->info;
    //Case 1: When there is only a single element on queue
    if(front->next == NULL)
    {
        temp = front;
        free(temp);
        front = NULL;
        rear = NULL;
    }
    else
    {
    //Case 2: When there are multiple elements in the queue
        temp = front;
        front = front->next;
        free(temp);    
    }
    return ret;
}
int checkF(NodeType *S)
{
    return front->info;
}

int checkR(NodeType *S)
{
    return rear->info;
}







