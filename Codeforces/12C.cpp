#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define ff          first
#define ss          second
#define vi          vector<int>
#define si          set<int>
#define FOR(i,n)    for(int i=0;i<n;i++)
#define fast        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SP(x)       fixed<<setprecision(x)
#define fWrite      freopen("out.txt", "w", stdout);//to write the output in a txt file
#define fRead       freopen("in.txt", "r", stdin);
#define asi         cout<<"Check"<<endl
#define bye         return 0
#define ok          cout<<"OK"<<endl
//lower_bound == Shoman othoba prothom boro element ta return korbe//iterator return kore
//upper bound mane first boro element return korbe
//string s(n,'a');

ll Digits(ll a)
{
    return(floor(log10(a))+1);
}
ll BMod(ll B,ll P,ll M)
{
    ll R=1;
    B=B%M;
    while(P)
    {
        if(P&1)
            R=(R*B)%M;
        P >>= 1;
        B=(B*B)%M;
    }
    return R;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}
ll lcm(ll a,ll b)
{
    return a*b/gcd(a,b);

}

bool cmp(const pair<int,string> &a,const pair<int,string> &b)
{
       return a.first>b.first;
}

int main()
{
    fast
    int n,m;
    cin>>n>>m;

    vector<int>v;
    FOR(i,n)
    {
        int x;
        cin>>x;
        v.pb(x);
    }
    sort(v.begin(),v.end());

    map<string,int>koyda;
    map<int,string>kifol;
    FOR(i,m)
    {
        string s;
        cin>>s;
        koyda[s]=koyda[s]+1;
    }


    vector<int>f;

    for(auto x:koyda)
    {
        f.pb(x.ss);
        //cout<<x.ff<<" "<<x.ss<<endl;
    }

    sort(f.begin(),f.end(),greater<int>());

    int sumMin=0;
    for(int i=0;i<f.size();i++)
    {
        sumMin+= (f[i] * v[i]);
        //cout<<sumMax<<" "<<v[i]<<" "<<f[i]<<endl;
    }

    sort(v.begin(),v.end(),greater<int>());
    int sumMax=0;
    for(int i=0;i<f.size();i++)
    {
        sumMax+=(f[i]*v[i]);
    }

    cout<<sumMin<<" "<<sumMax;

}

