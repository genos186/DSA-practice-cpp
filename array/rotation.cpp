#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if( b==0 )
        return a;

    else    
        return gcd(b,a%b);
}

void RotateLeft(int a[],int n,int d)
{
    d=d%n;
    int g_c_d=gcd(d,n);
    // cout<<d<<","<<g_c_d<<endl;

    for(int i=0;i<g_c_d;i++)
    {
        int temp=a[i];
        int j=i;
        while(1)
        {
            int k=j+d;
            if( k>=n )
                k=k-n;
            if( k==i )
                break;
            
            a[j]=a[k];
            j=k;
        }
        a[j]=temp;
    }

    for(int x=0;x<n;x++)
    {
        cout<<a[x]<<" ";
    }
    cout<<endl;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    int d=3;
    int n=sizeof(a)/sizeof(0);
    RotateLeft(a,n,d);
    return 0;
}



/*
void leftRotatebyOne(int arr[], int n)
{
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
 
    arr[n-1] = temp;
}
 
// Function to left rotate arr[] of size n by d
void leftRotate(int arr[], int d, int n)
{
    for (int i = 0; i < d; i++)
        leftRotatebyOne(arr, n);
}

int main()
{
    arr[]={....};
    n=size(arr);
    d=int;
    leftRotate(arr,d,n);
}
*/