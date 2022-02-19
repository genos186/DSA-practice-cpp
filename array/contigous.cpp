#include<bits/stdc++.h>
using namespace std;
//contiguous array
int findMaxLength(vector<int>& nums) 
{
    unordered_map<int,int> m;
    int sum=0,maxLen=0;
    
    for(int i=0;i<nums.size();i++)
    {
        sum+=(nums[i]==0)?-1:1;
        
        if( sum==0 )
            maxLen=i+1;
        if( m.find(sum)==m.end() )
            m[sum]=i;
        if( m.find(sum)!=m.end() )
        {
            if( maxLen<i-m[sum] )
                maxLen=i-m[sum];
        }
    }
    return maxLen;
}

int main()
{
    vector<int> inp{1,0,1,0,1};
    cout<<findMaxLength(inp)<<"\n";
    return 0;
}

/* longest sub-array with sum k
int lenOfLongSubarr(int A[],  int N, int K) 
{ 
    unordered_map<int,int> m;
    int sum=0,maxLen=0;
    for(int i=0;i<N;i++)
    {
        sum+=A[i];
        
        if( sum==K )
            maxLen=i+1;
        if( m.find(sum)==m.end() )
            m[sum]=i;
        if( m.find(sum-K)!=m.end() )
        {
            if( maxLen<i-m[sum-K] )
                maxLen=i-m[sum-K];
        }
    }
    return maxLen;
}
*/