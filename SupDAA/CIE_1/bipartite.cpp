#include <iostream>
#include <queue>
using namespace std;

#define V 5

void BFSColor(int graph[V][V], int src) {
    int color[V];   // -1 = unvisited, 0 = Blue, 1 = Red
    int level[V];   // store level of each node

    for (int i = 0; i < V; i++) {
        color[i] = -1;
        level[i] = -1;
    }

    queue<int> q;

    // start from source
    q.push(src);
    color[src] = 0;     // Blue
    level[src] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (graph[u][v] == 1) {
                
                // if not visited
                if (color[v] == -1) {
                    color[v] = 1 - color[u];   // alternate color
                    level[v] = level[u] + 1;
                    q.push(v);
                }
                // if same color → not bipartite
                else if (color[v] == color[u]) {
                    cout << "Graph is NOT Bipartite\n";
                    return;
                }
            }
        }
    }

    // Print result
    cout << "Node\tLevel\tColor\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << level[i] << "\t";
        if (color[i] == 0)
            cout << "Blue\n";
        else
            cout << "Red\n";
    }

    cout << "Graph is Bipartite\n";
}

int main() {
    int graph[V][V] = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {0,1,1,0,0},
        {0,0,1,0,0}
    };

    BFSColor(graph, 0);

    return 0;
}