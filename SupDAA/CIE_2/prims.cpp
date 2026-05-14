#include<iostream>
using namespace std;

#define V 5
#define INF 9999

int main()
{
    int graph[V][V] = {
        {0,4,0,0,8},
        {4,0,3,1,0},
        {0,3,0,7,0},
        {0,1,7,0,3},
        {8,0,0,3,0}
    };

    bool visited[V] = {false};
    visited[0] = true;

    int edges = 0;
    int mincost = 0;

    cout << "Edges in MST:\n";

    while(edges < V-1)
    {
        int min = INF;
        int a = 0, b = 0;

        for(int i=0;i<V;i++)
        {
            if(visited[i])
            {
                for(int j=0;j<V;j++)
                {
                    if(!visited[j] && graph[i][j])
                    {
                        if(graph[i][j] < min)
                        {
                            min = graph[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }
        }

        cout << a << " - " << b << " : " << min << endl;
        visited[b] = true;
        mincost += min;
        edges++;
    }

    cout << "Minimum Cost = " << mincost;

    return 0;
}