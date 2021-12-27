#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define MAX 10
struct LQ
{
    int front;
    int rear;
    int queue[MAX];
};
void enqueue(struct LQ*,int);
int dequeue(struct LQ*);
int check_front(struct LQ*);
int check_rear(struct LQ*);
int main()
{
    struct LQ q={0,-1};
    int choice,data;
    do
    {
        printf("\n");
        printf("Select an option. \n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. CHECK FRONT\n");
        printf("4. CHECK REAR\n");
        printf("5. EXIT.\n");
        printf(">");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter data : ");
                scanf("%d",&data);
                enqueue(&q,data);
                break;
            case 2:
                if(q.rear<q.front)
                    printf("QUEUE IS EMPTY \n");
                else
                    printf("Removed element is : %d \n",dequeue(&q));
                break;
            case 3:
                if(q.rear<q.front)
                    printf("QUEUE IS EMPTY \n");
                else
                    printf("Data : %d \n",check_front(&q));
                break;
            case 4:
                if(q.rear<q.front)
                    printf("QUEUE IS EMPTY \n");
                else
                    printf("Data : %d \n",check_rear(&q));
                break;
        }
        }while (choice!= 5);
        return 0;
}

void enqueue(struct LQ *Q, int a)
{
    if(Q->rear==MAX-1)
        printf("QUEUE IS FULL \n");
    else
    {
        Q->rear=Q->rear+1;
        Q->queue[Q->rear]=a;
        printf("%d was added into the queue\n",a);
    }
}
int dequeue(struct LQ *Q)
{
    int ret;
    ret=Q->queue[Q->front];
    Q->front=Q->front+1;
    return ret;
}
int check_front(struct LQ *Q)
{
    return (Q->queue[Q->front]);
}
int check_rear(struct LQ *Q)
{
    return (Q->queue[Q->rear]);
}