#include <stdio.h>
#define MAX 100
struct StaticList
{
    int data[MAX];
    int size;
};
typedef struct StaticList List;
void create_list(List*);
void ins(List*,int,int);
void del(List*,int);
void modify(List*,int,int);
void display(List*);
int main()
{
    List L;
    L.size = 0;
    int choice,element,pos;
    do
    {
        printf("\n");
        printf("Select a option. \n");
        printf("1. READ LIST\n");
        printf("2. INSERT ELEMENT\n");
        printf("3. DELETE ELEMENT\n");
        printf("4. MODIFY ELEMENT\n");
        printf("5. DISPLAY ELEMENTS\n");
        printf("6. EXIT\n");
        printf(">");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                create_list(&L);
                break;
            case 2:
                printf("Enter position : ");
                scanf("%d",&pos);
                printf("Enter element : ");
                scanf("%d",&element);
                ins(&L,pos,element);
                break;
            case 3:
                printf("Enter position : ");
                scanf("%d",&pos);
                del(&L,pos);
                break;
            case 4:
                printf("Enter position : ");
                scanf("%d",&pos);
                printf("Enter new element : ");
                scanf("%d",&element);
                modify(&L, pos, element);
                break;
            case 5:
                display(&L);
                break;
        }
        }while (choice!= 6);
        return 0;
}
void create_list(List *P)
{
    int i;
    printf("Enter number of elements to be inserted \n");
    scanf("%d",&(P->size));
    printf("Enter the elements of the list \n");
    for (i=0;i<P->size;i++)
    {
        scanf("%d",&(P->data[i]));
    }
    printf("SUCCESS");
}
void ins(List *P,int position, int e)
{
    int i;
    if(P->size>=MAX)
    {
        printf("Sorry, LIST Overﬂow\n");
    }
    for(i=P->size-1;i>=position-1;i--)
    {
        P->data[i+1]=P->data[i]; // shifting element to right by position
    }
    P->data[position-1]=e;
    printf("\nSUCCESS");
    P->size++;
}
void display(List *P)
{
    int i;
    printf("\nThe elements of list are \n");
    for(i=0;i<P->size;i++)
        printf("%d \t",P->data[i]);
}
void del(List *P, int position)
{
    int i;
    for(i=position;i<P->size;i++)
        {
            P->data[i-1]=P->data[i];// shifting elements to the left by 1 position
        }
    P->data[P->size-1]=0;// Store 0 at the last location to mark it empty
    printf("The element from Location %d has been deleted \n",position);
    P->size--;
}
void modify(List *P, int position, int e)
{
    int i;
    P->data[position-1]=e;
    printf("\nSUCCESS");
}

