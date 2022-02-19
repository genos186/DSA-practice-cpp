#include<bits/stdc++.h>
using namespace std;

// longest incrementing subsequence
int longestSubsequence(int a[],int n)
{
    int lis[n];
    for(int i=0;i<n;i++)
    {
        lis[i]=1;
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if( a[i]>a[j] && lis[i]<lis[j]+1 )
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    int max=lis[0];
    for(int i=1;i<n;i++)
    {
        cout<<lis[i]<<" ";
        max=(lis[i]>max) ? lis[i]:max;
    }
    cout<<"\n";
    return max;
}

int main()
{
    int a[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15,11};
    int n=sizeof(a)/sizeof(a[0]);
    int l=longestSubsequence(a,n);
    cout<<l<<"\n";
    return 0;
}