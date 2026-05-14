#include<iostream>
using namespace std;

#define E 5
#define V 4

struct Edge
{
    int u, v, w;
};

int parent[V];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void uni(int a, int b)
{
    parent[a] = b;
}

int main()
{
    Edge edges[E] = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    for(int i=0;i<V;i++)
        parent[i] = i;

    for(int i=0;i<E-1;i++)
    {
        for(int j=0;j<E-i-1;j++)
        {
            if(edges[j].w > edges[j+1].w)
            {
                Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }

    int mincost = 0;

    cout << "Edges in MST:\n";

    for(int i=0;i<E;i++)
    {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if(a != b)
        {
            cout << edges[i].u << " - " << edges[i].v << " : " << edges[i].w << endl;
            mincost += edges[i].w;
            uni(a,b);
        }
    }

    cout << "Minimum Cost = " << mincost;

    return 0;
}