#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> allPaths;

class Graph {
    int V; // No. of vertices in graph
    list<int>* adj; // Pointer to an array containing adjacency lists
 
    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int, int, vector<bool>, vector<int>, int&);
 
public:
    Graph(int V); // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
}
 
// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    vector<bool> visited(V,false);
 
    // Create an array to store paths
    vector<int> path(V);
    int path_index = 0;
 
    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}

void Graph::printAllPathsUtil(int u, int d, vector<bool> visited, vector<int> path, int& path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;
 
    // If current vertex is same as destination, then print
    // current path[]
    if (u == d) {
        allPaths.push_back(path);
        //for (int i = 0; i < path_index; i++)
        //    cout << path[i] << " ";
        //cout << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }
 
    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}
 
// Driver program
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
 
    int s = 2, d = 3;
    cout << "Following are all different paths from " << s << " to " << d << endl;
    g.printAllPaths(s, d);
    for(int i=0;i<allPaths.size();i++)
    {
        for(int j=0;j<allPaths[i].size();j++)
            cout<<allPaths[i][j]<<" ";
        cout<<"\n";
    }
 
    return 0;
}