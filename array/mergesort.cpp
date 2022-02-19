#include<bits/stdc++.h>
using namespace std;

void merge( int a[],int n,int b[],int m )
{
    int i=0,j=0,k=0;
    int o=m+n;
    int c[o];

    while( i<n || j<m )
    {
        if( a[i]<b[j] )
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
    }
    
    while( i<n )
    {
        c[k++]=a[i++];
    }
    while( j<m )
    {
        c[k++]=a[i++];
    }

    //printing merged array
    for(int x=0;x<o;x++)
    {
        cout<<c[x]<<" ";
    }
    cout<<endl;
}

int main()
{
    int a[]={1,3,5,7,9};
    int b[]={2,4,6,8};
    int n=sizeof(a)/sizeof(0);
    int m=sizeof(b)/sizeof(0);
    merge(a,n,b,m);
    return 0;
}