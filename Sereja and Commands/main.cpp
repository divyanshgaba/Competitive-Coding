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
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

const int N = 1e5;
const int M = 1e5;
const int T = 3;
const ll mod = 1e9 + 7;
ll com[2*N+1],add[2*N+1];
int n,m;

ll mod_pow(ll b,ll e)
{
    if(b == 0)
        return 0;
    if(e==0 || b==1)
        return 1;
    if(e == 1)
        return b;
    if(e==2)
        return (b*b)%mod;
    if(e&1)
        return (b*mod_pow(b,e-1))%mod;
    return mod_pow(mod_pow(b,e/2),2)%mod;
}
void build()
{
    for(int i =0;i<2*M;i++) com[i]=i<m?0:1;
}
void modify(int l,int r,ll val)
{
    for(l+=m,r+=m;l<r;l>>=1,r>>=1)
    {
        if(l&1) com[l] =(com[l]+ val)%mod,l++;
        if(r&1) --r,com[r] = (com[r]+ val)%mod;
    }
}

ll query(int p)
{
    ll res = 0;
    for(p+=m;p>0;p>>=1)
        res = (res + com[p])%mod;
    return res;
}
void push()
{
    for(int i = 1;i<m;i++)
    {
        com[i<<1] =  (com[i<<1] + com[i])%mod;
        com[i<<1|1] = (com[i<<1|1] +  com[i])%mod;
        com[i] =0;
    }
}
void modify_add(int l,int r,ll val)
{
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1) add[l] =(add[l]+ val)%mod,l++;
        if(r&1) --r,add[r] = (add[r]+ val)%mod;
    }
}
void push_add()
{
    for(int i = 1;i<n;i++)
    {
        add[i<<1] = (add[i<<1]+add[i])%mod;
        add[i<<1|1] = (add[i<<1|1] + add[i])%mod;
        add[i] = 0;
    }
}
int main()
{
	fast;
	int test=1;
	cin>>test;
    while(test--)
    {
        cin>>n>>m;

        build();
        memset(add,0,sizeof(add));
        vector<pair<int,pair<int,int>>> quer;
        for(int i = 0;i<m;i++)
        {
            int t,l,r;
            cin>>t>>l>>r;
            quer.PB(MP(t,MP(--l,--r)));

        }
        for(int i = m-1;i>=0;i--)
        {
            auto j = quer[i];
            if(j.F == 1)
                continue;
            modify(j.S.F,j.S.S+1,query(i));
        }
        push();
        //for(int  i =n;i<2*n;i++)            cout<<com[i]<<" ";cout<<endl;
        for(int i = 0;i<m;i++)
        {
            auto j = quer[i];
            if(j.F==2)
                continue;
            modify_add(j.S.F,j.S.S+1,com[i+m]);
        }
        push_add();
        for(int i = 0;i<n;i++)
        {
            cout<<add[i+n]<<" ";
        }
        cout<<endl;


    }
	return 0;

}
