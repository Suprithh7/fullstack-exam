#include<iostream>
using namespace std;

struct Edge
{
    int u, v, w;
};

int main()
{
    int V = 5;
    int E = 8;

    Edge edges[] = {
        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,2,5},
        {3,1,1},
        {4,3,-3}
    };

    int dist[V];

    for(int i=0;i<V;i++)
        dist[i] = 9999;

    dist[0] = 0;

    for(int i=1;i<V;i++)
    {
        for(int j=0;j<E;j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != 9999 && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    cout << "Vertex Distance from Source\n";

    for(int i=0;i<V;i++)
        cout << i << "\t" << dist[i] << endl;

    return 0;
}