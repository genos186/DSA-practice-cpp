#include<bits/stdc++.h>
using namespace std;

//First negative integer in every window of size k 
vector<int> printFirstNegativeInteger(vector<int> A,int N, int K) {
    vector<int> res;
    deque<int> di;
    int i;

    for(i=0;i<K;i++)
    {
        if( A[i]<0 )
            di.push_back(i);
    }

    for(;i<N;i++)
    {
        if( !di.empty() )
            res.push_back(A[di.front()]);

        else
            res.push_back(0);
        
        while( !di.empty() && di.front()<i-K+1 )
            di.pop_front();

        if( A[i]<0 )
            di.push_back(i);
    }

    if( !di.empty() )
        res.push_back(A[di.front()]);
    else
        res.push_back(0);

    return res;
}

int main()
{
    vector<int> inp{12, -1, -7, 8, -15, 30, 16, 28};
    int n=inp.size(),k=3;
    vector<int> res=printFirstNegativeInteger(inp,n,k);
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}