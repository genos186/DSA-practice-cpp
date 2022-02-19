#include<bits/stdc++.h>
using namespace std;

int minPath(vector<vector<int>> &grid)
{
    int m=grid.size();
    int n=grid[0].size();
    vector<int> cur(m,grid[0][0]);
    for(auto i:cur)
        cout<<i<<" ";
    cout<<"\n";

    for(int i=1;i<m;i++)
    {
        cur[i]=cur[i-1]+grid[i][0];
    }
    for(auto i:cur)
        cout<<i<<" ";
    cout<<"\n";

    for(int i=1;i<n;i++)
    {
        cur[0]=cur[0]+grid[0][i];
        for(int j=1;j<m;j++)
        {
            cur[j]=min(cur[j],cur[j-1])+grid[j][i];
        }
    }
    return cur[m-1];
}

int main()
{
    vector<vector<int>> grid
    {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    int res=minPath(grid);
    cout<<res<<"\n";
    return 0;
}