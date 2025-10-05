#include <iostream>
#include <vector>
#include <queue>
#define INF 99999999

using namespace std;

int vertex = 5, edge = 10;

void printPath(int node, vector<int> &parent) {
    if (node == -1) return;
    printPath(parent[node], parent);
    cout << "N" << node << " ";
}

int main()
{
    vector<pair<int, int>> G[vertex];

    int edges[10][3] = {
        {0,1,10}, {0,3,5}, {1,2,1}, {1,3,2}, {2,4,4},
        {3,1,3}, {3,2,9}, {3,4,2}, {4,0,7}, {4,2,6}
    };

    for(int e=0; e<edge; e++) {
        int u = edges[e][0];
        int v = edges[e][1];
        int w = edges[e][2];
        G[u].push_back(make_pair(v,w));
    }

    cout << "\nInput Graph:" << endl;
    for(int u=0; u<vertex; u++) {
        cout << "N" << u << " -----> ";
        for(int v=0; v<G[u].size(); v++)
            cout << "N" << G[u][v].first << ":" << G[u][v].second << "\t";
        cout << endl;
    }

    vector<int> dist(vertex, INF);
    vector<int> parent(vertex, -1);
    vector<bool> visit(vertex, false);

    int src = 0;
    dist[src] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.push(make_pair(dist[src], src));

    while(!Q.empty())
    {
        int u = Q.top().second;
        Q.pop();

        if (visit[u]) continue;
        visit[u] = true;

        for(int v=0; v<G[u].size(); v++)
        {
            int adjNode = G[u][v].first;
            int weight  = G[u][v].second;

            if(!visit[adjNode] && (dist[adjNode] > dist[u] + weight))
            {
                dist[adjNode] = dist[u] + weight;
                parent[adjNode] = u;
                Q.push(make_pair(dist[adjNode], adjNode));
            }
        }
    }

    cout << "\nNode: ";
    for(int i=0; i<vertex; i++)
        cout << "N" << i << "\t";

    cout << "\nDist: ";
    for(int i=0; i<vertex; i++)
        cout << dist[i] << "\t";

    cout << "\nPred: ";
    for(int i=0; i<vertex; i++)
        cout << parent[i] << "\t";

    cout << "\n\nShortest Path from Source (N0):" << endl;
    for(int i=0; i<vertex; i++) {
        cout << "N0 -> N" << i << " (cost=" << dist[i] << "): ";
        if (dist[i] == INF) {
            cout << "No path" << endl;
        } else {
            printPath(i, parent);
            cout << endl;
        }
    }

    return 0;
}

