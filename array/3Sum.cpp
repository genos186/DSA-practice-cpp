#include<bits/stdc++.h>
using namespace std;

//sum of 3 elements in a given array is equal to zero
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res{};
    sort(nums.begin(),nums.end());
    int n=nums.size();
    
    for(int i=0;i<n;i++)
    {
        int target=-nums[i];
        int first=i+1;
        int last=n-1;
        
        while( first<last )
        {
            int sum=nums[first]+nums[last];
            
            if( sum<target )
                first++;
            if( sum>target )
                last--;
            
            if( sum==target )
            {
                vector<int> triple{-target,nums[first],nums[last]};
                res.push_back(triple);
                
                while( first<last && nums[first]==triple[1] )
                    first++;
                while( last>first && nums[last]==triple[2] )
                    last--;
            }
        }
        while( i<n && nums[i]==nums[i+1] )
            i++;
    }
    return res;
}

int main()
{
    vector<int> inp{-1,0,1,2,-1,-4};

    vector<vector<int>> res=threeSum(inp);
    for(int i=0;i<res.size();i++)
    {
        for(auto j:res[i])
            cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}