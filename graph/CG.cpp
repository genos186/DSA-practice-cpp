#include<bits/stdc++.h>
using namespace std;
//checking prerequisite dependency of nodes in a graph based on incoming and outgoing links
//if cyclic graph then course completion not possible
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses,vector<int>());
        vector<int> d(numCourses,0);
        queue<int> q;
        
        for(auto i:prerequisites)
        {
            g[i[1]].emplace_back(i[0]);
            d[i[0]]++;
        }

        int res=0;
        for(int i=0;i<numCourses;i++)
        {
            if( d[i]==0 )
            {
                res++;
                q.push(i);
            }
        }
        
        while( !q.empty() && res<=numCourses )
        {
            int i=q.front();
            q.pop();
            for(int j:g[i])
            {
                if(--d[j]==0)
                {
                    q.push(j);
                    res++;
                }
            }
        }
        return (res==numCourses && q.empty());
    }


int main()
{
    int n=3;
    vector<vector<int>> sub
    {
        {0,1},
        {1,2},
        {2,0}
    };
    if(canFinish(n,sub))
    {
        cout<<"acyclic graph, possible\n";
    }
    else
    {
        cout<<"cyclic graph, not possible\n";
    }
}