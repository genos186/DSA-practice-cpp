#include<bits/stdc++.h>
using namespace std;

void spiral(vector<vector<int>> inp)
{
    int fr=0,lr=inp.size(),fc=0,lc=inp[0].size();

    while( fr<lr && fc<lc )
    {
        for(int i=fc;i<lc;i++)
            cout<<inp[fr][i]<<" ";
        fr++;

        for(int i=fr;i<lr;i++)
            cout<<inp[i][lc-1]<<" ";
        lc--;

        if( fr<lr )
        {
            for(int i=lc-1;i>=fc;i--)
                cout<<inp[lr-1][i]<<" ";
            lr--;
        }

        if( fc<lc )
        {
            for(int i=lr-1;i>=fr;i--)
                cout<<inp[i][fc]<<" ";
            fc++;
        }
    }
}

int main()
{
    vector<vector<int>> inp{
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20}
    };
    spiral(inp);
    return 0;
}