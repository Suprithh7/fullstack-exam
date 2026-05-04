#include <iostream>
#include <queue>
using namespace std;

#define V 5

void BFS(int graph[V][V], int start) {
    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "Reachable nodes: ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u + 1 << " "; // +1 to match node labels

        for (int v = 0; v < V; v++) {
            if (graph[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int graph[V][V] = {
        {0,1,1,1,0},
        {0,0,1,0,1},
        {0,0,0,1,1},
        {0,0,1,0,0},
        {0,0,0,0,0}
    };

    int source = 0; // node 1

    BFS(graph, source);

    return 0;
}