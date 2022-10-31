//
// Created by Sumit Suman on 09-12-2021.
//


#include <iostream>
#include <list>
using namespace std;
//graph class for DFS travesal
class DFSGraph
{
    int V;    // No. of vertices
    list<int> *adjList;    // adjacency list
    void DFS_util(int v, bool visited[]);  // A function used by DFS
public:
    // class Constructor
    DFSGraph(int V)
    {
        this->V = V;
        adjList = new list<int>[V];
    }
    // function to add an edge to graph
    void addEdge(int v, int w){
        adjList[v].push_back(w); // Add w to v’s list.
    }

    void DFS();    // DFS traversal function
};
void DFSGraph::DFS_util(int v, bool visited[])
{
    // current node v is visited
    visited[v] = true;
    cout << v << " ";

    // recursively process all the adjacent vertices of the node
    list<int>::iterator i;
    for(i = adjList[v].begin(); i != adjList[v].end(); ++i)
        if(!visited[*i])
            DFS_util(*i, visited);
}

// DFS traversal
void DFSGraph::DFS()
{
    // initially none of the vertices are visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // explore the vertices one by one by recursively calling  DFS_util
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFS_util(i, visited);
}

int main()
{
    // Create a graph
    DFSGraph gdfs(6);
    gdfs.addEdge(4, 5);
    gdfs.addEdge(4,6);
    gdfs.addEdge(4,3);
    gdfs.addEdge(5,1);
    gdfs.addEdge(1,1);
    gdfs.addEdge(2,4);
    gdfs.addEdge(3,2);
    gdfs.addEdge(3,6);
    gdfs.addEdge(6,2);
    gdfs.addEdge(6,5);

    cout << "Depth-first traversal for the given graph:"<<endl;
    gdfs.DFS();

    return 0;
}

/*
// DFS algorithm in C++

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};

// Initialize graph
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new list<int>[vertices];
    visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_front(dest);
}

// DFS algorithm
void Graph::DFS(int vertex) {
    visited[vertex] = true;
    list<int> adjList = adjLists[vertex];

    cout << vertex << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

int main() {
    Graph g(6);
    g.addEdge(4, 5);
    g.addEdge(4,6);
    g.addEdge(4,3);
    g.addEdge(5,1);
    g.addEdge(1,1);
    g.addEdge(2,4);
    g.addEdge(3,2);
    g.addEdge(3,6);
    g.addEdge(6,2);
    g.addEdge(6,5);

    g.DFS(2);

    return 0;
}
 */