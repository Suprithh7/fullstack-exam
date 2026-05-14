#include<iostream>
using namespace std;

#define N 4

int graph[N][N] = {
    {0,10,15,20},
    {10,0,35,25},
    {15,35,0,30},
    {20,25,30,0}
};

bool visited[N];
int mincost = 9999;

void tsp(int city, int count, int cost)
{
    if(count == N && graph[city][0])
    {
        if(cost + graph[city][0] < mincost)
            mincost = cost + graph[city][0];

        return;
    }

    for(int i=0;i<N;i++)
    {
        if(!visited[i] && graph[city][i])
        {
            visited[i] = true;
            tsp(i, count+1, cost + graph[city][i]);
            visited[i] = false;
        }
    }
}

int main()
{
    visited[0] = true;

    tsp(0,1,0);

    cout << "Minimum Cost = " << mincost;

    return 0;
}