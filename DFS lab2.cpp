#include<iostream>
#include<vector>
using namespace std;

int vertex=8, edge=14;
enum colorname {WHITE, GREY, BLACK};
int color[10], dis_time[10], fin_time[10];
int time;

void DFS_VISIT(vector<int> G[], int u)
{
    color[u] = GREY;
    time++;
    dis_time[u] = time;

    for(int v = 0; v < G[u].size(); v++) {
        int adj = G[u][v];
        if(color[adj] == WHITE) {
            DFS_VISIT(G, adj);
        }
    }

    color[u] = BLACK;
    time++;
    fin_time[u] = time;
    cout << u << "----";
}

void DFS(vector<int> G[])
{
    for(int u = 0; u < vertex; u++)
        color[u] = WHITE;
    time = 0;

    for(int u = 0; u < vertex; u++)
    {
        if(color[u] == WHITE)
            DFS_VISIT(G, u);
    }
}

int main()
{
    vector<int> graph[vertex];
    int u, v;
    cout << "Enter each edge" << endl;
    for(int e = 0; e < edge; e++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    cout << "\nInput Graph" << endl;
    for(int u = 0; u < vertex; u++)
    {
        cout << u << "--->";
        for(int v = 0; v < graph[u].size(); v++)
        {
            cout << " " << graph[u][v];
        }
        cout << endl;
    }

    cout << "\nDFS Traverse:" << endl;
    DFS(graph);
} // main

/*
0 1
0 4
1 2
1 3
2 1
3 3
4 0
4 3
5 0
5 2
5 6
6 2
6 7
7 5
*/
