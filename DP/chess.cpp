#include<bits/stdc++.h>
using namespace std;
// american express both elements should not be in the same row or column and their sum should be maximum
int maxSum(vector<vector<int>> &A,int i,int j,int m,int n)
{
    int msum=0;
    int s=A[i][j];
    int z=j;
    if( j==n-1 )
    {
        z=0;
    }

    for(int x=i;x<m;x++)
    {
        for(int y=z;y<n;y++)
        {
            if( x!=i )
            {
                if( y!=j )
                    msum=max(msum,s+A[x][y]);
            }
        }
    }
    return msum;
}

int solution(vector< vector<int> > &A) {
    // write your code in C++14 (g++ 6.2.0)
    int m=A.size();
    int n=A[0].size();
    int msum=0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            msum=max(msum,maxSum(A,i,j,m,n));
        }
    }
    return msum;
}

int main()
{
    vector<vector<int>> grid
    {
        {12,12},
        {12,12},
        {0,7}
    };
    int res=solution(grid);
    cout<<res<<"\n";
    return 0;
}