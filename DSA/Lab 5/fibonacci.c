#include <stdio.h>
#include <conio.h>
long int rfibo(int);
int main()
{
    int n;
    long int result;
    printf("Enter n: ");
    scanf("%d",&n);
    result=rfibo(n);
    printf("RESULT IS %ld",result);
    return 0;
}
long int rfibo(int n)
{
    if(n==1||n==2)
        return 1;
    else
        return rfibo(n-1)+rfibo(n-2);
}
