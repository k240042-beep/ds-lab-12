#include <iostream>
using namespace std;

#define MAX 6   // we will use nodes 1 to 5

// Queue for BFS
int queueArr[100], frontQ = 0, rearQ = 0;
void enqueue(int x) { queueArr[rearQ++] = x; }
int dequeue() { return queueArr[frontQ++]; }
bool isEmpty() { return frontQ == rearQ; }

// Stack for DFS
int stackArr[100], top = -1;
void push(int x) { stackArr[++top] = x; }
int pop() { return stackArr[top--]; }
bool isStackEmpty() { return top == -1; }

int main() {
    int adjList[MAX][MAX];
    int adjSize[MAX];
    int adjMatrix[MAX][MAX];

    for (int i = 0; i < MAX; i++) {
        adjSize[i] = 0;
        for (int j = 0; j < MAX; j++)
            adjMatrix[i][j] = 0;
    }

    auto addEdge = [&](int u, int v) {
        adjList[u][adjSize[u]++] = v;
        adjList[v][adjSize[v]++] = u;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    };

    addEdge(1, 4);
    addEdge(1, 2);
    addEdge(2, 4);
    addEdge(2, 5);
    addEdge(3, 5);
    addEdge(4, 5);

    cout << "Adjacency List:\n";
    for (int i = 1; i <= 5; i++) {
        cout << i << ": ";
        for (int j = 0; j < adjSize[i]; j++) {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }

    cout << "\nBFS Traversal starting from node 1:\n";
    bool visitedBFS[MAX] = {false};
    enqueue(1);
    visitedBFS[1] = true;

    while (!isEmpty()) {
        int node = dequeue();
        cout << node << " ";

        for (int i = 0; i < adjSize[node]; i++) {
            int nxt = adjList[node][i];
            if (!visitedBFS[nxt]) {
                visitedBFS[nxt] = true;
                enqueue(nxt);
            }
        }
    }

    cout << "\n\nDFS Traversal starting from node 1:\n";
    bool visitedDFS[MAX] = {false};
    push(1);
    visitedDFS[1] = true;

    while (!isStackEmpty()) {
        int node = pop();
        cout << node << " ";

        for (int i = 0; i < adjSize[node]; i++) {
            int nxt = adjList[node][i];
            if (!visitedDFS[nxt]) {
                visitedDFS[nxt] = true;
                push(nxt);
            }
        }
    }

    return 0;
}
