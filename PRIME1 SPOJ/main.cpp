/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
const ll N = 46346;
vector<ll> primes;
bool isprime[N+1];
void sieve()
{
    primes.PB(2);
    isprime[0] = isprime[1] = true;
    for(ll i = 2;i<=N;i+=2) isprime[i] = true;
    for(ll i = 3;i<=N;i+=2)
    {
        if(!isprime[i])
        {
            primes.PB(i);
            for(ll j = 2*i;j<=N;j+=i)
                isprime[j]=true;
        }
    }

}



int main()
{
    int t;
    sieve();
    scanf("%d",&t);
    while(t--)
    {
        ll a,b;
        scanf("%lld %lld",&a,&b);
        /*if(a <= N)
        {
            for(ll i = a;i<=min(b,N);i++)
            {
                if(!isprime[i])
                    printf("%lld\n",i);

            }
            a = min(b,N)+1;
        }*/
        if(a <=b)
        {
            bool mark[b-a+1];
            memset(mark,0,sizeof(mark));
            for(auto p:primes)
            {
                ll lo = max(2LL, a/p);
                for(ll k = lo*p;k<=b;k+=p)
                    mark[k-a] = true;
            }
            for(ll i = a;i<=b;i++)
            {
                if(!mark[i-a])
                    printf("%lld\n",i);
            }
        }



    }
}
