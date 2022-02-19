#include<bits/stdc++.h>
using namespace std;

int subk(vector<int> a,int k,int n)
{
    int mod[k];
    
    for(int p=0;p<n;p++)
    {
        mod[p]=0;
    }
    int cumsum=0;
    for(int i=0;i<n;i++)
    {
        cumsum+=a[i];
        mod[((cumsum%k)+k)%k]++;
    }

    int res=0;

    for(int i=0;i<n;i++)
    {
        if(mod[i]>1)
        {
            res+=mod[i]*(mod[i]-1)/2;
        }
    }
    res+=mod[0];
    return res;
}

int main()
{
    vector<int> arr = {4, 5, 0, -2, -3, 1,4};
    int k=5;
    int res=subk(arr,k,arr.size());
    cout<<"All possible combinations divisible by k are:"<<res<<endl;
    return 0;
}