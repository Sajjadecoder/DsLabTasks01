#include <iostream>
using namespace std;

struct Node
{
    int vertex;
    Node *next;
    Node(int v)
    {
        vertex = v;
        next = nullptr;
    }
};
class Graph
{
public:
    int numVertices;
    Node **adjList;

    Graph(int vertices)
    {
        numVertices = vertices;
        adjList = new Node *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            adjList[i] = nullptr;
        }
    }
    void addEdge(int src, int dest)
    {
        // Add dest to src's adjacency list
        Node *newNode = new Node(dest);
        Node *temp = adjList[src];
        if (!temp)
        {
            adjList[src] = newNode;
            return;
        }
        
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        // Since it's an undirected graph, add src to dest's adjacency list
        newNode = new Node(src);
        temp = adjList[dest];
        if (!temp)
        {
            adjList[dest] = newNode;
            return;
        }
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void displayGraph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << "Vertex " << i << ": ";
            Node *temp = adjList[i];
            while (temp)
            {
                cout << " -> " << temp->vertex;
                temp = temp->next;
            }
            cout << endl;
        }
    }
    ~Graph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            Node *temp = adjList[i];
            while (temp)
            {
                Node *toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
        }
        delete[] adjList;
    }
};
int main()
{
    int V,E;
    cout<<"Enter total vertices: ";
    cin>>V;
    cout<<"Enter total edges: ";
    cin>>E;

    Graph graph(V);
    for (int i = 0; i < E; i++)
    {
        int source,destination;
        cout<<"Enter source: ";
        cin>>source;
        cout<<"Enter destination: ";
        cin>>destination;
        graph.addEdge(source,destination);
    }
    
    graph.displayGraph();

    return 0;
}
