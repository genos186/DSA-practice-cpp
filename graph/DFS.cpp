 #include   
    
    vector<int>dfs(vector<int>adj, bool visited[], vector<int>&res, int s)
    {
        visited[s]=true;
        res.push_back(s);
        
        for(int i:adj[s])
        {
            if(visited[i]==false)
            {
                dfs(adj,res,i,visited);
            }
        }
    }
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    bool visited[V];
	    for(int i=0;i<V;i++)
	        visited[i]=false;
	    
	    vector<int> res;
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
	            dfs(adj,visited,res,i);
	        }
	    }
	    return res;
	}