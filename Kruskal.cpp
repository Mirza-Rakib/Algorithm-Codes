#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< pair <int, pair<int, int> > > G;//w,(u,v)

vector< pair <int, pair<int, int> > > MST;//w,(u,v)
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
    cout<<"Enter edge with weight: "<<endl;
    for (int e=0;e<edge; e++)
    {
        cin>> u >>v >> w;
        G.push_back(make_pair(w,make_pair(u,v)));
    }
    //Kurskal
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
    for (int i=0; i<MST.size(); i++)
    {
        cout<<"("<<MST[i].second.first<<","<<MST[i].second.second<<"): "<<MST[i].first<<endl;
    }
}




/*
1 2 6
1 3 12
2 3 5
2 5 14
2 8 8
3 4 9
3 6 7
5 8 3
6 7 15
6 8 10
*/
