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
    for(ll p = 2;p*p<=n;p++)
    {
        if(pr[p]==true)
        {
            for(ll i =p*2;i<=n;i+=p)
                pr[i]=false;
        }
    }
    for(int i =2;i<=n;i++)
        if(pr[i])
            prime.PB(i);
}
ll score(ll n)
{
    priority_queue<ll> pq;
    ll ans =1;
    for(auto it:prime)
    {
        int cnt=1;
        if(n/it <= 1)
            break;
        while(n%it ==0)
        {
            cnt++;
            n/=it;
        }
        if(cnt>1)
            ans*=cnt,pq.push(cnt);
        //cout<<ans<<endl;
    }
    if(n>2)
        ans*=2,pq.push(2);
    //cout<<pq.size()<<endl;
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
	sieve(min(max(1e3,sqrt(b+1)+1),1e6));
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

