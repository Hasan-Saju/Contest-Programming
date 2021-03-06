#include<bits/stdc++.h>
using namespace std;

const int N=510;
vector<int>V[N];
int vis[N];
int dis[N];
map<string,int>m;

void bfs(int s)
{
    memset(vis,0,sizeof(vis));
    vis[s]=1;
    dis[s]=1;
    queue<int>Q;
    Q.push(s);

    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for(int i=0;i<V[x].size();i++)
        {
            int u=V[x][i]; //cout<<"check"<<u<<" "<<m["Polycarp"]<<endl;
            if(!vis[u])
            {
                //cout<<"check"<<endl;
                vis[u]=1;
                dis[u]=dis[x]+1;
                //cout<<dis[u]<<" ";
                Q.push(u);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;

    int a=1;
    for(int i=0;i<n;i++)
    {
        string f,s,repost;
        cin>>f>>repost>>s;

        transform(f.begin(),f.end(),f.begin(),::tolower);
        transform(s.begin(),s.end(),s.begin(),::tolower);

        if(m.find(s)==m.end())
        {
            m[s]=a++;
        }
        if(m.find(f)==m.end())
        {
            m[f]=a++;
        }
        int x=m[f];
        int y=m[s];
        //V[x].push_back(y);
        V[y].push_back(x);
    }
    bfs(1);
    int maxx=-9999;
    for(int i=0;i<=2*n;i++)
        maxx=max(maxx,dis[i]);
    cout<<maxx;
//    for(auto z:m )
//    cout<<z.first<<" "<<z.second<<endl;
}
