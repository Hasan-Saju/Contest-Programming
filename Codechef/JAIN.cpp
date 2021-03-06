#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define ff          first
#define ss          second
#define vi          vector<int>
#define si          set<int>
#define pi          pair<int,int>
#define FOR(i,n)    for(int i=0;i<n;i++)
#define fast        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SP(x)       fixed<<setprecision(x)
#define fWrite      freopen("out.txt", "w", stdout);//to write the output in a txt file
#define fRead       freopen("in.txt", "r", stdin);
#define asi         cout<<"Check"<<endl
#define bye         return 0
#define ok          cout<<"OK"<<endl
#define NL          "\n"
//lower_bound == Shoman othoba prothom boro element ta return korbe//iterator return kore
//upper bound mane first boro element return korbe
//string s(n,'a');
//ans+=string(r,'R');

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
ll POW(ll  B,ll P)
{
    ll R=1;
    while(P) {
        if(P&1)
            R=R*B;
        B=B*B;
        P>>=1;
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

int ara[32];
void process(string s)
{
    int mask=0;
    for(auto ch:s )
    {
        if(ch=='a')mask=mask | (1<<0);
        else if(ch=='e')mask=mask | (1<<1);
        else if(ch=='i')mask=mask | (1<<2);
        else if(ch=='o')mask=mask | (1<<3);
        else if(ch=='u')mask=mask | (1<<4);
    }
    ara[mask]++;

}


int main()
{
    fast
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        memset(ara,0,sizeof(ara));

        FOR(i,n)
        {
            string s;
            cin>>s;
            process(s);
        }

        ll ans=0;
        for(int i=1;i<32;i++)
        {
            for(int j=i+1;j<32;j++)
            {
                if((i|j)==31)ans=ans+(ara[i]*ara[j]);
            }
        }
        ans=ans+(ara[31]*(ara[31]-1))/2;

        cout<<ans<<NL;




        }
    }



