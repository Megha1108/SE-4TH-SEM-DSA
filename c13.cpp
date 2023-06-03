/*Represent a given graph using adjacency matrix/list to perform DFS and using adjacency 
list to perform BFS. Use the map of the area around the college as the graph. Identify the 
prominent land marks as nodes and perform DFS and BFS on that.*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//----------------------------------------------------------------------------
// Graph class
class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyMatrix;
    vector<vector<int>> adjacencyList;
//----------------------------------------------------------------------------
public:
    Graph(int vertices) {
        numVertices = vertices;

        // Initialize adjacency matrix
        adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 0));

        // Initialize adjacency list
        adjacencyList.resize(numVertices);
    }
//----------------------------------------------------------------------------
    void addEdge(int src, int dest) {
        adjacencyMatrix[src][dest] = 1;
        adjacencyMatrix[dest][src] = 1;

        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);
    }
//----------------------------------------------------------------------------
    void DFS(int startVertex, vector<bool>& visited) {
        visited[startVertex] = true;
        cout << startVertex << " ";

        for (int i = 0; i < numVertices; ++i) {
            if (adjacencyMatrix[startVertex][i] == 1 && !visited[i]) {
                DFS(i, visited);
            }
        }
    }
//----------------------------------------------------------------------------
    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        cout << "DFS Traversal: ";
        DFS(startVertex, visited);
        cout << endl;
    }
//----------------------------------------------------------------------------
    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> bfsQueue;

        visited[startVertex] = true;
        bfsQueue.push(startVertex);

        cout << "BFS Traversal: ";
//----------------------------------------------------------------------------
        while (!bfsQueue.empty()) {
            int currVertex = bfsQueue.front();
            bfsQueue.pop();
            cout << currVertex << " ";

            for (int i = 0; i < adjacencyList[currVertex].size(); ++i) {
                int adjVertex = adjacencyList[currVertex][i];
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    bfsQueue.push(adjVertex);
                }
            }
        }

        cout << endl;
    }
};
//----------------------------------------------------------------------------
int main() {
    // Create a graph
    Graph graph(7);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(1, 5);
    graph.addEdge(2, 4);
    graph.addEdge(2, 6);

    // Perform DFS starting from vertex 0
    graph.DFS(0);

    // Perform BFS starting from vertex 0
    graph.BFS(0);

    return 0;
}
