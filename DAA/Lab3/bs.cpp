#include <iostream>
#define MAX 30000
int t = 0;
using namespace std;
void bSearch(int A[], int l, int r, int key)
{
    int flag = -1, m;t++;
    t++;
    if(l<=r)
    {
        m = (l+r)/2;t++;
        t++;
        if(key == A[m])
            {
                flag = m;t++;
            }
        else if(key < A[m])
        {
            t++;
            t++;
            return bSearch(A, l, m-1, key);
        }
        else
        {
            t++;
            return bSearch(A, m+1, r, key);
        }
    }
    t++;
    if(flag == -1)
        cout<<"Search Unsuccessfull"<<endl;
    else
    {
        cout<<"Search Successfull. Element found at index "<<flag<<endl;t++;
    }
}
int main()
{
    int A[MAX], n, i, key;
    cout<<"How many elements? ";
    cin>>n;
    for(i=0; i<n; i++)
        A[i] = rand();
    cout<<n<<" elements generated"<<endl;
    cout<<"Key ? ";
    cin>>key;
    bSearch(A,0,n-1,key);
    cout<<"T(n) = "<<t<<endl;
    return 0;
}