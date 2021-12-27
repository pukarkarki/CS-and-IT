#include <stdio.h>
#define MAX 5
struct CQ
{
    int size, front, rear, queue[MAX];
};
void enqueue(struct CQ*,int);
int dequeue(struct CQ*);
int main()
{
    struct CQ q={0, 0, -1};
    int choice,data;
    do
    {
        printf("\n");
        printf("Select an option. \n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. EXIT.\n");
        printf(">");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                if(q.size == MAX)
                    printf("QUEUUE IS FULL\n");
                else
                    {
                        printf("Enter data : ");
                        scanf("%d",&data);
                        enqueue(&q, data);
                        printf("%d Enqueued\n",data);
                    }
                break;
            case 2:
                if(q.size == 0)
                    printf("QUEUE IS EMPTY\n");
                else
                    printf("Removed element is : %d \n",dequeue(&q));
                break;
            case 3:
                printf("BYE\n");
                break;
        }
        }while (choice!= 3);
        return 0;
}

void enqueue(struct CQ *Q, int a)
{
        Q->rear = (Q->rear+1)%MAX;
        Q->queue[Q->rear]=a;
        Q->size += 1;
}
int dequeue(struct CQ *Q)
{
    int ret = Q->queue[Q->front];
    Q->front=(Q->front+1)%MAX;
    Q->size -= 1;
    return ret;
}
