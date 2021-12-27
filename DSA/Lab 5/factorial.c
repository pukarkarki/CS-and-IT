#include <stdio.h>
#include <conio.h>
long int fact(int n);
int main()
{
    int n;
    long int result;
    printf("Enter a number : ");
    scanf("%d",&n);
    result=fact(n);
    printf("Result : %ld \n",result);
    return 0;
}

long int fact(int n)
{
    if(n==0)
        return 1;
    else
        return n*fact(n-1);
}
