#include<bits/stdc++.h>
using namespace std;

#define V 9

int minDist(int dist[],bool sptSet[])
{
    int min=INT_MIN, min_index;

    for(int i=0;i<V;i++)
    {
        if (sptSet[i] == false && dist[i] <= min)
        {
            min = dist[i]; 
            min_index = i;
        }            
    }
    return min_index;
}

void print_dist(int dist[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}

void dijakstra(int graph[V][V],int src)
{
    int dist[V];
    bool sptSet[V];

    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }

    dist[src]=0;

    for(int count=0;count<V-1;count++)
    {
        int u=minDist(dist,sptSet);
    
        sptSet[u]=true;

        for(int j=0;j<V;j++)
        {
            if ( !sptSet[j] && graph[u][j] && dist[u]!=INT_MAX && dist[u]+graph[u][j]<dist[j] )
                    dist[j] = dist[u] + graph[u][j];
        }
    }

    print_dist(dist);
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijakstra(graph, 0);
 
    return 0;
}