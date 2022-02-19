#include<bits/stdc++.h>
using namespace std;

void Qsort( int a[],int n )
{
    int i,j,key;

    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        
        while( j>=0 && a[j]>key )
        {
            a[j+1]=a[j];
            j-=1;
        }
        a[j+1]=key;
    }

    for(int k=0;k<n;k++)
    {
        cout<<a[k]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int a[]={3,7,4,9,1,2};
    int n=sizeof(a)/sizeof(0);
    Qsort(a,n);
    return 0;
}