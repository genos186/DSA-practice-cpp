#include<iostream>
#include <list>
 
using namespace std;

// adjacency list representation
class Graph
{
    int V;    
    list<int> *adj;  
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // prints BFS traversal from a given source s
    void BFS(int s); 
    //print all adjacent vertices to each vertex
    void print_adjlist();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::print_adjlist()
{
    for( int i=0;i<V;i++)
    {
        cout<<"\n Vertex"<<i<<"->";
        for(int nbr:adj[i])
        {
            cout<<nbr<<" ";
        }
    }
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    g.print_adjlist();
    return 0;
}



// ---------------------------------------------------------------------------------------------------------------------------------------------------------
/*
vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    list<int> queue;
	    bool *visited=new bool[V];
	    for( int i=0;i<V;i++ )
	    {
	        visited[i]=false;
	    }
	    
	    visited[0]=true;
	    queue.push_back(0);
	    
	    vector<int> res;
	    while(!queue.empty())
	    {
	        int s=queue.front();
	        res.push_back(s);
	        queue.pop_front();
	        
	        for(int i:adj[s])
	        {
	            if(!visited[i])
	            {
	                visited[i]=true;
	                queue.push_back(i);
	            }
	        }
	    }
	    return res;
	}
    */