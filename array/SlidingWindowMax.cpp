#include<bits/stdc++.h>
using namespace std;

//finding maximum within each window of size k
void slider(int a[],int n, int k)
{
    vector<int> result;
    int max=0;
    for(int i=0;i<=n-k;i++)
    {
        max=a[i];
        for(int j=1;j<k;j++)
        {
            if( max<a[j+i] )
                max=a[j+i];
        }
        result.emplace_back(max);
    }

    for(int k=0;k!=result.size();k++)
    {
        cout<<result[k]<<" ";
    }
    cout<<endl;
}

int main()
{
    int a[]={8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int n=sizeof(a)/sizeof(0);
    int k=4;
    slider(a,n,k);
    return 0;
}