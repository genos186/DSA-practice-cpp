#include<bits/stdc++.h>
using namespace std;

void addEdge(map<string,pair<string,int>> &adj, string u, string v, int wt)
{
    adj.insert(make_pair<u,make_pair<v,wt>>);
}

void calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        int n=equations.size();
        map<string,pair<string,double>> adj;
        for(int i=0;i<n;i++)
        {
            addEdge(adj,equations[i][0],equations[i][1],values[i]);
        }
        map<string,pair<string,int>>::iterator it;
        for(it=adj.begin();it!=adj.end();it++)
        {
            cout<<it->first<<" "<<it->second<<"\n";
        }
        cout<<"\n";
    }
    
int main()
{
    vector<vector<string>> equations
    {
        {'a','b'},
        {'b','c'}
    };
    vector<double> values{2.0,3.0};
    vector<vector<string>> queries
    {
        {'a','c'},
        {'b','a'},
        {'a','e'},
        {'a','a'}
    };
    calcEquation(equations,values,queries);
    return 0;
}