#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int vertex = 8, edge = 14;
enum colorname {WHITE, GREY, BLACK};
int color[10], dis_time[10], fin_time[10];
int Time;


char nodeName[10] = {'A','B','C','D','E','F','G','H'};

void BFS(vector<int> G[], int s)
{
    queue<int> q;

    color[s] = GREY;
    Time++;
    dis_time[s] = Time;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < G[u].size(); v++)
        {
            int adj = G[u][v];
            if (color[adj] == WHITE)
            {
                color[adj] = GREY;
                Time++;
                dis_time[adj] = Time;
                q.push(adj);
            }
        }

        color[u] = BLACK;
        Time++;
        fin_time[u] = Time;

    }
}

void BFS_initialize(vector<int> G[])
{
    for(int u = 0; u < vertex; u++)
    {
        color[u] = WHITE;
        dis_time[u] = 0;
        fin_time[u] = 0;
    }
    Time = 0;

    for(int u = 0; u < vertex; u++)
    {
        if (color[u] == WHITE)
            BFS(G, u);
    }
}

int main()
{
    vector<int> graph[vertex];

    int edges[14][2] = {
        {0,1},{0,4},{1,2},{1,3},{2,1},{3,3},
        {4,0},{4,3},{5,0},{5,2},{5,6},{6,2},{6,7},{7,5}
    };

    for(int e=0; e<edge; e++)
    {
        int u = edges[e][0];
        int v = edges[e][1];
        graph[u].push_back(v);
    }

    cout << "\nInput Graph:" << endl;
    for(int u = 0; u < vertex; u++)
    {
        cout << nodeName[u] << " --->";
        for(int v = 0; v < graph[u].size(); v++)
        {
            cout << " " << nodeName[graph[u][v]];
        }
        cout << endl;
    }

    cout << "\nBFS Traverse:" << endl;
    BFS_initialize(graph);

    cout << "\nBFS sequence using finish time:" << endl;
    for(int t=1; t<=2*vertex; t++)
    {
        for(int i=0; i<vertex; i++)
        {
            if(fin_time[i]==t)
                cout << nodeName[i] << "-----";
        }
    }
    cout << endl;

    return 0;
}
