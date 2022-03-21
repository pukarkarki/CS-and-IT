#include <stdio.h>
#include <conio.h>
int LinearSearch(int a[],int n,int key);
int BinarySearch(int a[],int n,int key);
int b_search_recursive(int l[],int arrayStart,int arrayEnd,int a);
int main()
{
    int a[20],n,key,i;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element to be searched : ");
    scanf("%d",&key);
    printf("Using Linear Search, the location of %d is %d \n",key,LinearSearch(a,n,key));
    printf("Using Binary Search, the location of %d is %d \n",key,BinarySearch(a,n,key));
    printf("Using RBinary Search, the location of %d is %d \n",b_search_recursive(a,0,n-1,key));
    return 0;
}
int LinearSearch(int a[],int n,int key)
{
    int i,flag=-1;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
            flag=i;
    }
    return flag;
}
int BinarySearch(int a[],int n,int key)
{
    int mid,first=0,last=n-1;
    while(first<=last)
    {
        mid=(first+last)/2;
        if(key<a[mid])
            last=mid-1;
        else if(key>a[mid])
            first=mid+1;
        else
            return mid;

    }
    return -1;
}
int b_search_recursive(int l[],int arrayStart,int arrayEnd,int a)
{
  int m,pos;
  if (arrayStart<=arrayEnd)
  {
    m=(arrayStart+arrayEnd)/2;
    if (l[m]==a)
      return m;
    else if (a<l[m])
      return b_search_recursive(l,arrayStart,m-1,a);
    else
      return b_search_recursive(l,m+1,arrayEnd,a);
   }
   return -1;
}
