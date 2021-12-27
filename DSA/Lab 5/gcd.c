#include <stdio.h>
#include <conio.h>
int gcd(int,int);
int main()
{
    int a,b,result;
    printf("Enter a: ");
    scanf("%d",&a);
    printf("Enter b: ");
    scanf("%d",&b);
    result=gcd(a,b);
    printf("GCD IS %d",result);
    return 0;
}
int gcd(int a,int b)
{
    if (b==0)
		return a;
      else
        return gcd(b,a%b);
}
