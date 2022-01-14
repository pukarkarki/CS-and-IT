#include <iostream>
#include <chrono>
using namespace std;
int t = 0;
long int fibo(int n)
{
    t++;t++;t++;
    if(n == 0 || n==1)
    {
        t++;
        return 1;
    }
    else
    {
        int i;
        long int c = 0, a = 1, b = 1;t++;t++;t++;
        for(i=1,t++; i<= n-2; i++,t++)
        {
            t++;
            c = a + b;t++;
            a = b;t++;
            b = c;t++;
        }
        t++;
        return c;
    }
}
int main()
{
    int n;
    cout<<"Enter term: ";
    cin>>n;
    auto start = chrono::high_resolution_clock::now();
    cout<<"The "<<n<<"th Fibonaci term is "<<fibo(n)<<endl;
    cout<<"T(n) = "<<t<<endl;
    return 0;
}