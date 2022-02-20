#include <stdio.h>
#include <conio.h>
void move(int n,char source,char destination,char temp);
int main()
{
    int n;
    printf("Enter number of discs : ");
    scanf("%d",&n);
    move(n,'A','C','B');
    return 0;
}
void move(int n,char source,char destination,char temp)
{
    if(n==1)
    {
        printf("Move disc 1 from %c to %c \n",source,destination);
    }
    else
    {
        move(n-1,source,temp,destination);
        printf("Move disc %d from %c to %c \n",n,source,destination);
        move(n-1,temp,destination,source);
    }
	}
