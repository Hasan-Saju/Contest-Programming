#include<bits/stdc++.h>
using namespace std;

#define ll          long long
#define ull         unsigned long long
#define pb          push_back
#define mp          make_pair
#define ff          first
#define ss          second
#define vi          vector<int>
#define si          set<int>
#define pi          pair<int,int>
#define FOR(i,n)    for(int i=0;i<n;i++)

#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define max5(a,b,c,d,e)     max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e)     min(min3(a,b,c),min(d,e))

#define fast        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define SP(x)       fixed<<setprecision(x)
#define fWrite      freopen("out.txt", "w", stdout);//to write the output in a txt file
#define fRead       freopen("in.txt", "r", stdin);
#define PI          2*acos(0.0)
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
    while(P)
    {
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

bool prime[1000001];
vector<ll>pl;

void sieve()
{
    int maxx=1000000;
    memset(prime,true,sizeof(prime));

    prime[0]=prime[1]=false;

    for(int i=4;i<=maxx;i+=2)
        prime[i]=false;

    for(int i=3; i*i<=maxx ; i+=2)
    {
        if(prime[i]==true)
        {
            for(int j=i*i; j<=maxx; j+=2*i)
                prime[j]=false;
        }
    }

    pl.pb(2);
    for(int i=3;i<=maxx;i+=2)
        if(prime[i])
        pl.pb(i);


}

int main()
{
    //fast
    sieve();
    int t;
    scanf("%d",&t);

    for(int j=1; j<=t; j++)
    {
        ll n,temp;
        int ans=1;
        scanf("%lld",&n);
        temp=n;


        for(int i=0;i<pl.size() and pl[i]<=sqrt(temp) ;i++)
        {
            if(temp%pl[i]==0)
            {
                int k=0;

                while(temp%pl[i]==0)
                    k++, temp/=pl[i];
                if(k!=0)ans*=(k+1);
            }
        }

        if(temp>1)ans*=2;

        printf("Case %d: %d\n",j,ans-1);        /// 1 base means only 0 (so kono number e create hobe na)

    }

}
