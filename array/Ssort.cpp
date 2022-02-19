#include<bits/stdc++.h>
using namespace std;

void Ssort(int a[],int n)
{
    int min,i,j;

    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
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
    Ssort(a,n);
    return 0;
}