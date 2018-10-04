#include <iostream>
#include <list>
#include <fstream>

using namespace std;

// This class represents a directed graph using adjacency
// list representation
class Graph
{
public:
    int V;    // No. of vertices
    list<int> *adj;    // adjacency lists
    Graph(int V);  // Constructor
    void addEdge(int v, int w, int weight); // adds an edge
    void addEdge(int u, int v);

    // finds shortest path from source vertex ‘s’ to
    // destination vertex ‘d’.
    int findShortestPath(int s, int d);

    // print shortest path from a source vertex ‘s’ to
    // destination vertex ‘d’.
    int printShortestPath(int parent[], int s, int d);
};
// A directed graph using adjacency list representation
class AGraph
{
    int V;    // No. of vertices in graph
    list<int> *aadj; // Pointer to an array containing adjacency lists

    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int , int , bool [], int [], int &);

public:
    AGraph(int V);   // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};

AGraph::AGraph(int V)
{
    this->V = V;
    aadj = new list<int>[V];
}

void AGraph::addEdge(int u, int v)
{
    aadj[u].push_back(v); // Add v to u’s list.
}


// Prints all paths from 's' to 'd'
void AGraph::printAllPaths(int s, int d)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index);
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void AGraph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        for (int i = 0; i<path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = aadj[u].begin(); i != aadj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[2*V];
}

void Graph::addEdge(int v, int w, int weight)
{
    // split all edges of weight 2 into two
    // edges of weight 1 each.  The intermediate
    // vertex number is maximum vertex number + 1,
    // that is V.
    if (weight==2)
    {
        adj[v].push_back(v+V);
        adj[v+V].push_back(w);
    }
    else // Weight is 1
        adj[v].push_back(w); // Add w to v’s list.
}

// To print the shortest path stored in parent[]
int Graph::printShortestPath(int parent[], int s, int d)
{
    static int level = 0;

    // If we reached root of shortest path tree
    if (parent[s] == -1)
    {
        cout << "Shortest Path between " << s << " and "
        << d << " is "  << s << " ";
        return level;
    }

    printShortestPath(parent, parent[s], d);

    level++;
    if (s < V)
        cout << s << " ";

    return level;
}

// This function mainly does BFS and prints the
// shortest path from src to dest. It is assumed
// that weight of every edge is 1
int Graph::findShortestPath(int src, int dest)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[2*V];
    int *parent = new int[2*V];

    // Initialize parent[] and visited[]
    for (int i = 0; i < 2*V; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[src] = true;
    queue.push_back(src);

    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;

    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        int s = queue.front();

        if (s == dest)
            return printShortestPath(parent, s, dest);

        queue.pop_front();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it
        // visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
                parent[*i] = s;
            }
        }
    }
    return 1;
}

// Driver program to test methods of graph class
int main()
{
    ifstream myfile;
    myfile.open ("graph1.dat");

    // Create a graph given in the above diagram
    int V, x, y, z;
    int src, dest;
    int choice = 1;
    myfile>>V;
    AGraph ag(1000000);
    Graph g(V);

    while(!myfile.eof()){
        myfile >> x;
        myfile >> y;
        ag.addEdge(x, y);
        myfile >> z;
        g.addEdge(x, y, z);
    }

    myfile.close();

    while(choice!=0){
        cout << "0. Exit\n";
        cout << "1. Print all simple paths\n";
        cout << "2. Print shortest path from any source to any destination\n";
        cout << "Enter an option: ";
        cin >> choice;
        switch (choice) {
            case 0:
                return 0;
                break;
            case 1:
                cout << "Enter source: ";
                cin >> src;
                cout << "Enter destination: ";
                cin >> dest;
                cout << "Following are all different paths from " << src
                << " to " << dest << endl;
                ag.printAllPaths(src, dest);
                break;
            case 2:
                cout << "Enter source: ";
                cin >> src;
                cout << "Enter destination: ";
                cin >> dest;
                cout << "\nShortest Distance between " << src
                << " and " << dest << " is "
                << g.findShortestPath(src, dest);
                cout << endl;
                break;

            default:
                cout << choice << " is not a valid choice.\n";
                break;
        }
    }

    return 0;
}
