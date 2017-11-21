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
const ll N = 5e5+55;
ll n,L,R;
struct node
{
    ll val;
    ll leftin,leftout;
    ll rightin,rightout;
    ll st,en;
    node()
    {
        val = 0;
        leftin=rightin=leftout=rightout=-1;
        st = en = -1;
    }
};
node seg[4*N];
void header()
{
    cout<<"ind\tval\tleftin\tleftout\trightin\trightout\tst\ten\n";
}
void print(ll i)
{
    cout<<i<<"\t"<<seg[i].val<<"\t"<<seg[i].leftin<<"\t"<<seg[i].leftout<<"\t"<<seg[i].rightin<<"\t"<<seg[i].rightout<<"\t\t"<<seg[i].st<<"\t"<<seg[i].en<<endl;
}
node combine(node a,node b)
{
    node c;
    c.val = a.val+b.val;
    c.st = a.st;
    c.en = b.en;
    if(a.leftin!=-1)
        c.leftin=a.leftin;
    else
        c.leftin=b.leftin;
    if(b.rightin!=-1)
        c.rightin=b.rightin;
    else
        c.rightin=a.rightin;
    if(a.leftout != -1)
        c.leftout=a.leftout;
    else
        c.leftout=b.leftout;
    if(b.rightout != -1)
        c.rightout=b.rightout;
    else
        c.rightout=a.rightout;
    if(c.leftin!=-1&&c.leftout!=-1)
    {
        if(c.leftin>c.leftout)
            c.leftin=-1;
    }
    if(c.rightin!=-1&&c.rightout!=-1)
    {
        if(c.rightin<c.rightout)
            c.rightin=-1;
    }
    if(a.rightin != -1)
    {
        if(b.leftout!=-1)
        {
            c.val += (b.leftout-b.st)*(a.rightin);
            if(a.rightout!=-1)
                c.val += (b.leftout-b.st)*(-a.rightout);
            else
                c.val += (b.leftout-b.st)*(-a.st+1);
        }
        else
        {
            c.val += (b.en-b.st+1)*(a.rightin);
            if(a.rightout!=-1)
                c.val += (b.en-b.st+1)*(-a.rightout);
            else
                c.val += (b.en-b.st+1)*(-a.st+1);
        }
    }
    if(b.leftin != -1)
    {
        if(a.rightin !=-1)
        {
            if(b.leftout!=-1)
                c.val += (b.leftout-b.leftin)*(a.en-a.rightin);
            else
                c.val += (b.en-b.leftin+1)*(a.en-a.rightin);
        }
        else
        {
            if(b.leftout!=-1)
            {
                if(a.rightout!=-1)
                {
                    c.val += (b.leftout-b.leftin)*(a.en-a.rightout);
                }
                else
                {
                    c.val += (b.leftout-b.leftin)*(a.en-a.st+1);
                }
            }
            else
            {
                if(a.rightout!=-1)
                {
                    c.val += (b.en-b.leftin+1)*(a.en-a.rightout);
                }
                else
                {
                    c.val += (b.en-b.leftin+1)*(a.en-a.st+1);
                }
            }
        }
    }
    return c;

}
void build()
{
    for(ll i = n-1;i>0;i--)
    {
        seg[i] = combine(seg[i<<1],seg[i<<1|1]);
    }
}
node init(ll val,ll p)
{
    node a;
    a.val=0;
    a.st=a.en=p+1;
    if(val>R)
        a.leftout=a.rightout=p+1;
    else if(val<=R&&val>=L)
        a.leftin=a.rightin=p+1,a.val=1;
    return a;
}
void modify(ll p,ll val)
{
    seg[p+n]=init(val,p);
    for(p+=n;p>>=1;) seg[p]=combine(seg[p<<1],seg[p<<1|1]);
}
ll query(ll l,ll r)
{
    node resr,resl;
    bool lt=false,rt=false;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(lt&&l&1)
            resl = combine(resl,seg[l++]);
        else if(!lt&&l&1)
            resl=seg[l++],lt=true;
        if(rt&&r&1)
            resr = combine(seg[--r],resr);
        else if(!rt&&r&1)
            resr=seg[--r],rt=true;
    }
    if(lt&&rt)
        return combine(resl,resr).val;
    else if(lt)
        return resl.val;
    return resr.val;
}
ll nearest(ll n)
{

    for(ll i = 62;i>=0;i--)
    {
        if((1<<i)&n)
            return 1<<(i+1);
    }
}
int main()
{
    fast;
    ll q;
    cin>>n>>q>>L>>R;
    n = nearest(n);
    for(ll i = 0;i<n;i++)
    {
        seg[i+n]=init(0,i);
    }
    //cout<<n<<endl;
    build();
    while(q--)
    {
        ll t;
        cin>>t;
        if(t==1)
        {
            ll x,val;
            cin>>x>>val;
            modify(x-1,val);
           // header();            for(ll i = 0;i<2*n;i++)                print(i);
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            cout<<query(l-1,r)<<endl;
        }
    }
    return 0;
}
