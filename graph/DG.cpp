#include<bits/stdc++.h>
using namespace std;
//Directed Graph 
int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> count(N + 1, 0);
        for (auto t : trust)
            count[t[0]]--, count[t[1]]++;
        for (int i = 1; i <= N; ++i) {
            if (count[i] == N - 1) return i;
        }
        return -1;
    }

int main()
{
    vector<vector<int>> trust
    {
        {1,2},
        //{1,4},
        {2,3}
        //{2,4},
        //{4,3}
    };
    int n=3;
    vector<int> count(n + 1, 0);
    for(int i:count)
    {
        cout<<i;
    }
    cout<<endl;
    
    int res=findJudge(n,trust);
    cout<<res;

    return 0;
}