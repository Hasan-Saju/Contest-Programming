#include<bits/stdc++.h>
using namespace std;

#define MAXN 100005
struct edge {
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

int pr[MAXN];
vector<edge>e;

int Find(int r)
{
    return pr[r]= (pr[r]==r) ? r: Find(pr[r]);
}

int mst(int n)
{
    sort(e.begin(),e.end());
    for(int i=0;i<=n;i++)
        pr[i]=i;

    int kount=0,s=0;
    for(int i=0;i<e.size();i++)
    {
        int u= Find(e[i].u);
        int v= Find(e[i].v);

        if(u!=v)
        {
            pr[u]=v;
            kount++;
            s+=e[i].w;
            if(kount==n-1)break;
        }
    }
    return s;
}

int main()
{
    int node,m;
    cin>>node>>m;
    map<pair<int,int>,int>mp;
    map<pair<int,int>,int>::iterator it;
    pair<int,int> key;

    for(int i=1;i<=node;i++)
    {
        for(int j=i+1;j<=node;j++)
        {
            key=make_pair(i,j);
            mp[key]=0;
        }
    }

    for(int i=0;i<m;i++)
    {
        int x,y,a,b;
        cin>>x>>y;
        a=min(x,y);
        b=max(x,y);
        key=make_pair(a,b);
        mp[key]=1;
    }

    for(it=mp.begin();it!=mp.end();it++)
    {
        key=it->first;
        edge get;
        get.u=key.first;
        get.v=key.second;
        get.w=it->second;

        e.push_back(get);
    }



    cout<<mst(node);
}









