#include <iostream>
using namespace std;

// Node structure for linked list
struct Node
{
    int vertex; // The vertex this node represents
    Node *next; // Pointer to the next node
    Node(int v)
    {
        vertex = v;
        next = nullptr;
    }
};
// Graph structure
class Graph
{
public:
    int numVertices; // Number of vertices
    Node **adjList;  // Array of pointers to linked lists

    // Constructor
    Graph(int vertices)
    {
        numVertices = vertices;
        adjList = new Node *[vertices];
        for (int i = 0; i < vertices; i++)
        {
            adjList[i] = nullptr;
        }
    }

    // Function to add an edge
    void addEdge(int src, int dest)
    {
        // Add dest to src's adjacency list
        Node *newNode = new Node(dest);
        newNode->next = adjList[src];
        adjList[src] = newNode;

        // Since it's an undirected graph, add src to dest's adjacency list
        newNode = new Node(src);
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }
    // Helper function to remove a node from a linked list
    void removeNode(Node *&head, int vertex)
    {
        Node *current = head;
        Node *prev = nullptr;

        // Traverse the list to find the node to remove
        while (current != nullptr && current->vertex != vertex)
        {
            prev = current;
            current = current->next;
        }

        // If the node is found
        if (current != nullptr)
        {
            if (prev == nullptr)
            {
                // Node to remove is the head
                head = current->next;
            }
            else
            {
                // Node is in the middle or end
                prev->next = current->next;
            }
            delete current; // Free the memory
        }
    }

    // Function to remove an edge from the graph
    void removeEdge(int src, int dest)
    {
        // Remove dest from src's adjacency list
        removeNode(adjList[src], dest);

        // Remove src from dest's adjacency list
        removeNode(adjList[dest], src);
    }

    // Function to display the adjacency list
    void displayGraph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << "Vertex " << i << ":";
            Node *temp = adjList[i];
            while (temp)
            {
                cout << " -> " << temp->vertex;
                temp = temp->next;
            }
            cout << endl;
        }
    }

    // Destructor to free memory
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

// Main function
int main()
{
    int vertices = 5;

    Graph graph(vertices);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.displayGraph();

    return 0;
}
