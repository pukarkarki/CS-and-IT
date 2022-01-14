#include <iostream>
using namespace std;
int t = 0;
int gcd(int a, int b)
{
    t++;
    if(b == 0)
    {
        t++;
        return a;
    }
    else
    {
        int r;
        while(b != 0)
        {
            t++;
            r = a%b;t++;
            a = b;t++;
            b = r;t++;
        }
        t++;
        return a;
    }
}
int main()
{
    int a, b;
    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;
    cout<<"GCD = "<<gcd(a,b)<<endl;
    cout<<"T(n) = "<<t<<endl;
    return 0;
}
