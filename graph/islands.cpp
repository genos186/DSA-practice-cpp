#include<bits/stdc++.h>
using namespace std;

int islandArea(vector<vector<int>> &map,int i,int j,int m,int n)
{
    if( i>=0 && i<m && j>=0 && j<n && map[i][j]==1 )
    {
        map[i][j]=0;
        return 1+islandArea(map,i+1,j,m,n)+islandArea(map,i-1,j,m,n)+islandArea(map,i,j+1,m,n)+islandArea(map,i,j-1,m,n);
    }
    return 0;
}

void totalislands(vector<vector<int>> &map,int m,int n)
{
    vector<int> res;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if( map[i][j]==1 )
            {
                res.push_back(islandArea(map,i,j,m,n));
            }
        }
    }

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    vector<vector<int>> map{
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0},
    };

    totalislands(map,map.size(),map[0].size());
    return 0;
}