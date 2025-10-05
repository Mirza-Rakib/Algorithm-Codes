#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< pair <int, pair<int, int> > > G;

vector< pair <int, pair<int, int> > > MST;
int vertex=8, edge=10;
int *vSet;

void make_set()
{
    vSet= new int [vertex+1];
    for(int i=1; i<=vertex; i++)
        vSet[i]=i;
}
int find_set(int u)
{
    if(u==vSet[u])
        return u;
    else
        return find_set(vSet[u]);
}

void union_set(int u, int v)
{
    vSet[u]=vSet[v];
}

int main()
{
    int u,v,w;

    int edges[10][3] = {
        {1,2,6},{1,3,12},{2,3,5},{2,5,14},{2,8,8},
        {3,4,9},{3,6,7},{5,8,3},{6,7,15},{6,8,10}
    };

    for(int i=0; i<edge; i++){
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];
        G.push_back(make_pair(w, make_pair(u,v)));
    }

    sort(G.begin(),G.end());
    cout<<"Sorted Edge: "<<endl;
    cout<<"Edge\t"<<" Weight"<<endl;
    for(int i=0; i<G.size(); i++)
    {
        cout<<"("<<G[i].second.first<<","<<G[i].second.second<<"): "<<G[i].first<<endl;
    }

    make_set();
    int uloc,vloc;
    for(int i =0; i<G.size(); i++)
    {
        uloc=find_set(G[i].second.first);
        vloc=find_set(G[i].second.second);
        if(uloc!=vloc)
        {
            MST.push_back(G[i]);
            union_set(uloc,vloc);
        }
    }

    cout<<"MST"<<endl;
    int totalCost=0; //total cost
    for (int i=0; i<MST.size(); i++)
    {
        cout<<"("<<MST[i].second.first<<","<<MST[i].second.second<<"): "<<MST[i].first<<endl;
        totalCost += MST[i].first;
    }
    cout << "Total Cost of MST: " << totalCost << endl;
}

