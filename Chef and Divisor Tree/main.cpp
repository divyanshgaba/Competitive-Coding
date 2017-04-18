#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

map<ll,ll> sc;
vector<ll> prime;
vector<ll> realprime;
void sieve(ll n)
{
    bool pr[n+1];
    memset(pr,true,sizeof(pr));
    pr[0]=pr[1]=false;
    for(ll p = 2;p<=sqrt(n)+1;p++)
    {
        if(pr[p]==true)
        {
            //cout<<p<<endl;
            prime.PB(p);
            for(ll i =p*2;i<=n;i+=p)
                pr[i]=false;
        }
    }
}
void segmentedSieve(int n)
{

    int limit = floor(sqrt(n))+1;
    sieve(limit);
    int low  = limit;
    int high = 2*limit;
    while (low < n)
    {
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));

        for (int i = 0; i < prime.size(); i++)
        {
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];

            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                prime.PB(i);//cout<<i<<endl;

        // Update low and high for next segment
        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
    //cout<<realprime.size()<<endl;
}
ll score(ll n)
{
    if(n==1)
        return 1;
    priority_queue<ll> pq;
    ll ans =1;
    for(auto it:prime)
    {
        int cnt=1;
        while(n%it ==0)
        {
            cnt++;
            n/=it;
        }
        if(cnt>1)
            ans*=cnt,pq.push(cnt);
        if(n==1)
            break;
        //cout<<ans<<endl;
    }
    //cout<<ans<<endl;
    ll tmp,hold=ans;
    while(!pq.empty())
    {
        ll top = pq.top();
        //cout<<top<<endl;
        pq.pop();
        tmp = hold/top;
        top--;
        hold = tmp*top;
        ans +=(tmp*top);
        if(top>1)
            pq.push(top);
    }
    return ans;

}

int main()
{
	fast;
	ll a,b;
	cin>>a>>b;
    segmentedSieve(b);
        //sort(primes.begin(),primes.end());
    //for(auto it:prime)        cout<<it<<" ";    cout<<endl;
	ll ans =0;
	for(ll i =a;i<=b;i++)
    {
        //cout<<i<<" "<<score(i)<<endl;
        ans+=(score(i)-1);
        //cout<<score(i);
    }
    cout<<ans;
	return 0;

}

