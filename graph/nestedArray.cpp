#include<bits/stdc++.h>
using namespace std;

int search(vector<int> nums,int x,int n)
{
    int i=x,count=0;
    while( nums[i]!=-1 )
    {
        int y=nums[i];
        nums[i]=-1;
        i=y;
        cout<<y<<" ";
        count++;
    }
    cout<<"\n";
    return count;
}

int arrayNesting(vector<int>& nums) {
    int n=nums.size(),longest=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        longest=max(longest,search(nums,i,n));
    }
    return longest;
}

int main()
{   //              0,1,2,3,4,5,6
    vector<int> inp{5,4,0,3,1,6,2};
    cout<<arrayNesting(inp)<<"\n";
    return 0;
}