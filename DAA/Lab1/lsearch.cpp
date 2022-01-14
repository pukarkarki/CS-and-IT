#include <iostream>
int t = 0;
using namespace std;
void lSearch(int A[], int key, int n)
{
    int i, flag = 0;t++;
    for(i=0, t++; i<n; i++,t++)
       {
           t++;
           t++;
           if(A[i] == key)
            {
                flag = 1;t++;
                cout<<"Search Successful. Element found at "<<i<<"th position"<<endl;t++;
                t++;
                return;
            }
        }
    t++;
    if(flag == 0)
        cout<<"Search Unsuccessful. Element not found"<<endl;
}
int main()
{
    int A[10000],n, i, key;
    cout<<"How many elements? ";
    cin>>n;
    for(i=0; i<n; i++)
        A[i] = rand();
    cout<<"Enter element to search: ";
    cin>>key;
    lSearch(A,key,n);
    cout<<"T(n) = "<<t<<endl;
    return 0;
}