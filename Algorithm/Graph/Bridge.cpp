#include<bits/stdc++.h>
using namespace std;

const int N=100005;
vector<int>V[N];
int vis[N];
int in[N];
int low[N];
int timer=1;

void dfs(int node, int par)
{
    vis[node]=1;
    in[node]=low[node]=timer;   //first a shobar in ar low same
    timer++;

    for(int child : V[node])
    {
        if(child==par) continue;

        if(vis[child]==1) //agei visit hoye gese mane eita backtrack
        {
            //edge node-child is a back edge

            low[node]=min(low[node],in[child]);
        }
        else
        {
            //edge node-child forward edge
            dfs(child,node);

            if(low[child]>in[node])             //backtrack er shomoy execute hobe
                cout<<node<<" - "<<child<<" is a bridge"<<endl;

            low[node]=min(low[node],low[child]);

        }
    }
}

int main()
{
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;
        V[x].push_back(y);
        V[y].push_back(x);
    }
    dfs(1,-1);
}
