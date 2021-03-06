#include<bits/stdc++.h>
using namespace std;

int field[60][60];
int dis[60][60];
int vis[60][60];
int X[] ={1,0,0,-1};
int Y[] ={0,1,-1,0};
int n;
string s1="",s2="";
int flag=0;

vector<int>v1;
vector<int>v2;


void bfs(int x,int y)
{
    memset(vis,0,sizeof(vis));
    vis[x][y]=1;
    dis[x][y]=0;
    queue<int>Q;
    Q.push(x);
    Q.push(y);

    while(!Q.empty())
    {
        int ux,uy;
        ux=Q.front();
        Q.pop();
        uy=Q.front();
        Q.pop();

        if(!flag)
        {
            s1+= (ux+'0');
            s1+=(uy+'0');
        }
        else
        {
            s2+=(ux+'0');
            s2+=(uy+'0');
        }


        if(!flag)
        {
            v1.push_back(ux);
            v1.push_back(uy);
        }
        else
        {
            v2.push_back(ux);
            v2.push_back(uy);
        }



        for(int i=0;i<4;i++)
        {
            int vx,vy;
            vx=ux+X[i];
            vy=uy+Y[i];

            if((vx>=1 && vy>=1) and (vx<=n && vy<=n) and field[vx][vy]==0)
            {
                if(!vis[vx][vy] and !dis[vx][vy])
                {
                    vis[vx][vy]=1;
                    dis[vx][vy]=dis[ux][uy]+1;
                    Q.push(vx);
                    Q.push(vy);
                }
            }
        }
    }
    flag=1;
}

int main()
{

    cin>>n;
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;

    string s[n];
    for(int i=0;i<n;i++)
        cin>>s[i];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            field[i+1][j+1]=s[i][j]-'0';
        }
    }

    bfs(r1,c1);
    bfs(r2,c2);

    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());

    int Min=999999;

    if(s1==s2)
    {
        if(s1.size()==2 and r1==c2)goto label;
        cout<<"0";
        //cout<<s1<<" "<<s2;
    }
    else
    {
        label:
        for(int i=0;i<v1.size();i=i+2)
        {
            for(int j=0;j<v2.size();j=j+2)
            {
                int cost;
                cost=(abs(v1[i]-v2[j])*abs(v1[i]-v2[j]))+(abs(v1[i+1]-v2[j+1])*abs(v1[i+1]-v2[j+1]));
                Min=min(cost,Min);
            }
        }
        cout<<Min;
    }



}
