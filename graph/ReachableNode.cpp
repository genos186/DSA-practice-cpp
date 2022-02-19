#include <bits/stdc++.h>
using namespace std;

// DFS function
int dfs(int s, vector<int> adj[], vector<bool> visited, int nodes)
{
	// Adding all the edges connected to the vertex
	int adjListSize = adj[s].size();
	visited[s] = true;
	for (long int i = 0; i < adj[s].size(); i++) {
		if (visited[adj[s][i]] == false) {
			adjListSize += dfs(adj[s][i], adj, visited, nodes);
		}
	}
	return adjListSize;
}

void maxEdges(vector<int> adj[], int nodes)
{
	vector<int> res;
	vector<bool> visited(nodes, false);
	for (long int i = 1; i <= nodes; i++) {
		if (visited[i] == false) {
			int adjListSize = dfs(i, adj, visited, nodes);
			/* for finding largest graph with most number of nodes
				int res=max(res,adjListSize/2);
			*/
            if( find(res.begin(),res.end(),adjListSize/2)==res.end() )
			    res.push_back(adjListSize/2);
		}	
	}
    int fres=0;
    for(int i=0;i<res.size();i++)
    {
        if( res[i]>0 )
        {
            fres+=pow(res[i],1/2);
        }
        cout<<res[i]<<" ";
    }
    cout<<"\n"<<fres;
}

// Driver code
int main()
{
	int nodes = 10;
	vector<int> adj[nodes+1];

	// Edge from vertex 1 to vertex 2
	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(2);
	adj[2].push_back(4);
  	adj[4].push_back(2);
  	adj[3].push_back(5);
  	adj[5].push_back(3);
  	
  	adj[7].push_back(8);
  	adj[8].push_back(7);

    maxEdges(adj, nodes);
	return 0;
}