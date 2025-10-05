#include<iostream>
#include<vector>
using namespace std;
int vertex=8, edge=14;
enum colorname {WHITE, GREY, BLACK};
int color[10], dis_time[10], fin_time[10];
int time;

char nodeName[10] = {'A','B','C','D','E','F','G','H'};

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

    int edges[14][2] = {
        {0,1},{0,4},{1,2},{1,3},{2,1},{3,3},
        {4,0},{4,3},{5,0},{5,2},{5,6},{6,2},{6,7},{7,5}
    };

    for(int e=0; e<edge; e++){
        u = edges[e][0];
        v = edges[e][1];
        graph[u].push_back(v);
    }

    cout << "\nInput Graph" << endl;
    for(int u = 0; u < vertex; u++)
    {
        cout << nodeName[u] << "--->";
        for(int v = 0; v < graph[u].size(); v++)
        {
            cout << " " << nodeName[graph[u][v]];
        }
        cout << endl;
    }

    cout << "\nDFS Traverse (Finish Time Order):" << endl;
    DFS(graph);

    cout << "\nDFS sequence using finish time:" << endl;
    for(int t=1; t<=2*vertex; t++)
    {
        for(int i=0; i<vertex; i++)
        {
            if(fin_time[i]==t)
                cout << nodeName[i] << "----";
        }
    }
    cout << endl;
}
