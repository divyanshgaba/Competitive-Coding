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
const int N = 100001;
const ll P = 1e9 + 7;
const ll B = 45;
ll a[N];
//---Pre Sums and Square sums seg ---
ll sum[N],sqsum[N];
void calc_sums(int n)
{
    memset(sum,0,sizeof(sum));
    memset(sqsum,0,sizeof(sqsum));
    sum[0] = a[0],sqsum[0] = a[0]*a[0];
    for(int i = 1;i<n;i++)
    {
        sum[i] = sum[i-1] + a[i];
        sqsum[i] = sqsum[i-1] + a[i]*a[i];
    }
}
ll get_sum(int a,int b)
{
    return sum[b] - a!=0?sum[a-1]:0;
}
ll get_sq_sum(int a,int b)
{
    return sqsum[b] - a!=0?sqsum[a-1]:0;
}
pair<ll,ll> get_p_q(int a, int b,int c,int d)
{
    ll p_minus_q = get_sum(a,b) - get_sum(c,d);
    ll p_plus_q  = (get_sq_sum(a,b) - get_sq_sum(c,d))/(p_minus_q);

    return make_pair((p_plus_q + p_minus_q)/2, (p_plus_q - p_minus_q)/2);
}
//----pre Sum and sq sum seg ends----

//----Hashing seg---
ll mod_pow(ll b,ll e)
{
    if(e==0||b==1)
        return 1;
    if(e == 1)
        return b;
    if(e == 2)
        return (b*b)%P;
    if(e&1)
        return (b*mod_pow(b,e-1))%P;
    return mod_pow(mod_pow(b,e/2)%P,2)%P;
}
ll pre_hash[N];
void calc_pre_hash(int n)
{
    memset(pre_hash,0,sizeof(pre_hash));
    pre_hash[0] = mod_pow(a[0],B);
    for(int i = 1;i<n;i++)
        pre_hash[i] = (pre_hash[i-1] + mod_pow(a[i],B))%P;
}
ll get_hash(int a,int b)
{
    ll ans = (pre_hash[b] - a!=0?pre_hash[a-1]:0)%P;
    if(ans <0)
        ans +=P;
    return ans;
}
//---Hashing seg ends

bool one_mismatch(int a,int b,int c,int d)
{
    auto p_q = get_p_q(a,b,c,d);
    ll p = p_q.F, q = p_q.S;
    if((get_hash(a,b) - mod_pow(p,B))%P == (get_hash(c,d) - mod_pow(q,B))%P)
        return true;
    return false;
}

void pre(int n)
{
    calc_sums(n);
    calc_pre_hash(n);
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,q;
        cin>>n>>q;
        for(int i = 0;i<n;i++) cin>>a[i];
        pre(n);
        while(q--)
        {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            a--,b--,c--,d--;
            if(get_hash(a,b) == get_hash(c,d))
            {
                cout<<"YES\n";
            }
            else
            {
                if(one_mismatch(a,b,c,d))
                {
                    cout<<"TO DO\n";
                }
                else
                {
                    cout<<"NO\n";
                }
            }

        }
    }
    return 0;
}
