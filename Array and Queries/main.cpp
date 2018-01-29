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
const ll mod = 1e9+7;
struct node
{

    int val;
    int l,r;
    int ind;
    node()
    {
        val = 0;
        l = r = -1;
    }
};
struct CompareId
{
    using is_transparent = void; // for example with void,
                                 // but could be int or struct CanSearchOnId;
    bool operator()(node const& a, node const& b) const
    {
        if(a.val!=b.val)
        return a.val < b.val;
        return a.ind<b.ind;
    }
    bool operator()(int a, node const& b) const
    {
        return a < b.val;
    }
    bool operator()(node const& a, int b) const
    {
        return a.val < b;
    }
};


int main()
{
	fast;
	int n;
	cin>>n;
	node g[n];
	multiset<node,CompareId> l,r;
	for(int i = 0;i<n;i++)
    {
        cin>>g[i].val;
        g[i].ind = i;
        l.insert(g[i]);
        //cout<<(*(l.upper_bound(g[i]))).val<<endl;
        r.insert(g[i]);
    }

    /*for(auto i:l)
        cout<<i.val<<" ";
    cout<<endl;
    for(auto i:r)
        cout<<i.val<<" ";
    cout<<endl;*/
    ll cnt = n;
    ll answer = 0;
    for(int i = 0;i<n;i++)
    {
        int id = i;
        //cout<<g[id].val<<" "<<g[id].l<<" "<<g[id].r<<" "<<g[id].ind<<endl;
        if(g[i].l == -1)
        {
            auto it = r.lower_bound(g[i].val - 1);
            //if(it != r.begin())     --it;
            int ind = (*it).ind;
            //cout<<(*it).val<<" --- "<<i<<endl;
            if(g[ind].val == (g[i].val - 1))
            {
                r.erase(it);
                auto jt = l.find(g[i]);
                l.erase(jt);
                g[ind].r = i;
                g[i].l = ind;
                cnt--;
            }
        }
        if(g[i].r == -1)
        {
            auto it = l.lower_bound(g[i].val + 1);
            if(it != l.end())
            {
                int ind = (*it).ind;
                if(g[ind].val == (g[i].val + 1))
                {
                    l.erase(it);
                    auto jt = r.find(g[i]);
                    r.erase(jt);
                    g[ind].l = i;
                    g[i].r = ind;
                    cnt--;
                }
            }
        }
        //cout<<g[id].val<<" "<<g[id].l<<" "<<g[id].r<<" "<<g[id].ind<<endl;
    }
   /* for(auto i:l)
        cout<<i.val<<" ";
    cout<<endl;
    for(auto i:r)
        cout<<i.val<<" ";
    cout<<endl;*/
    int q;
    cin>>q;
    ll ans[q+1];
    for(ll i = 1;i<=q;i++)
    {
        //cout<<"start----------"<<endl;
        int id,val;
        cin>>id>>val;
        id--;
        //cout<<g[id].val<<" "<<g[id].l<<" "<<g[id].r<<" "<<g[id].ind<<endl;
        int x,y;
        x = y = -1;
        if(g[id].l!=-1)
            assert(g[g[id].l].r == id),g[g[id].l].r=-1,r.insert(g[g[id].l]),x = g[id].l,g[id].l=-1,cnt++;
        else
            l.erase(l.find(g[id]));
        if(g[id].r!=-1)
            assert(g[g[id].r].l == id),g[g[id].r].l=-1,l.insert(g[g[id].r]),y=g[id].r,g[id].r=-1,cnt++;
        else
            r.erase(r.find(g[id]));
        g[id].val = val;
        l.insert(g[id]);
        r.insert(g[id]);
        if(g[id].l == -1)
        {
            auto it = r.lower_bound(g[id].val - 1);
            int ind = (*it).ind;
            //cout<<g[ind].val<<" --- "<<ind<<" ---- "<<id<<endl;
            if((g[ind].val) == (g[id].val - 1))
            {
                r.erase(it);
                auto jt = l.find(g[id]);
                l.erase(jt);
                g[ind].r = id;
                g[id].l = ind;
                cnt--;
                //cout<<ind<<" left con with "<<id<<endl;
            }
        }
        if(g[id].r == -1)
        {
            auto it = l.lower_bound(g[id].val + 1);
            if(it != l.end()){
            //cout<<(*it).val<<" +++ "<<id<<endl;
            int ind = (*it).ind;
            if(g[ind].val == (g[id].val + 1))
            {

                l.erase(it);
                auto jt = r.find(g[id]);
                r.erase(jt);
                g[ind].l = id;
                g[id].r = ind;
                cnt--;
                //cout<<ind<<" right con with "<<id<<endl;
            }
            }
        }
          /*      cout<<g[id].val<<" "<<g[id].l<<" "<<g[id].r<<" "<<g[id].ind<<endl;
        cout<<"first----------"<<endl;
        for(auto i:l)
        cout<<i.val<<" ";
    cout<<endl;
    for(auto i:r)
        cout<<i.val<<" ";
    cout<<endl;*/
        if(x!=-1)
        {
            id=x;
            //cout<<g[id].val<<" "<<g[id].l<<" "<<g[id].r<<" "<<g[id].ind<<endl;
            if(g[id].l == -1)
            {
                auto it = r.lower_bound(g[id].val - 1);
                int ind = (*it).ind;
                //cout<<g[ind].val<<" --- "<<ind<<" ---- "<<id<<endl;
                if((g[ind].val) == (g[id].val - 1))
                {
                    r.erase(it);
                    auto jt = l.find(g[id]);
                    l.erase(jt);
                    g[ind].r = id;
                    g[id].l = ind;
                    cnt--;
                    //cout<<ind<<" left con with "<<id<<endl;
                }
            }
            if(g[id].r == -1)
            {
                auto it = l.lower_bound(g[id].val + 1);
                if(it != l.end()){
                //cout<<(*it).val<<" +++ "<<id<<endl;
                int ind = (*it).ind;
                if(g[ind].val == (g[id].val + 1))
                {

                    l.erase(it);
                    auto jt = r.find(g[id]);
                    r.erase(jt);
                    g[ind].l = id;
                    g[id].r = ind;
                    cnt--;
                    //cout<<ind<<" right con with "<<id<<endl;
                }
                }
            }
        }
               /* cout<<"second----------"<<endl;

                cout<<g[id].val<<" "<<g[id].l<<" "<<g[id].r<<" "<<g[id].ind<<endl;

        for(auto i:l)
        cout<<i.val<<" ";
    cout<<endl;
    for(auto i:r)
        cout<<i.val<<" ";
    cout<<endl;*/
        if(y!=-1)
        {
            id=y;
            //cout<<g[id].val<<" "<<g[id].l<<" "<<g[id].r<<" "<<g[id].ind<<endl;
            if(g[id].l == -1)
            {
                auto it = r.lower_bound(g[id].val - 1);
                int ind = (*it).ind;
                //cout<<g[ind].val<<" --- "<<ind<<" ---- "<<id<<endl;
                if((g[ind].val) == (g[id].val - 1))
                {
                    r.erase(it);
                    auto jt = l.find(g[id]);
                    l.erase(jt);
                    g[ind].r = id;
                    g[id].l = ind;
                    cnt--;
                    //cout<<ind<<" left con with "<<id<<endl;
                }
            }
            if(g[id].r == -1)
            {
                auto it = l.lower_bound(g[id].val + 1);
                if(it != l.end()){
                //cout<<(*it).val<<" +++ "<<id<<endl;
                int ind = (*it).ind;
                if(g[ind].val == (g[id].val + 1))
                {

                    l.erase(it);
                    auto jt = r.find(g[id]);
                    r.erase(jt);
                    g[ind].l = id;
                    g[id].r = ind;
                    cnt--;
                    //cout<<ind<<" right con with "<<id<<endl;
                }
                }
            }
        }
        /*for(auto i:l)
        cout<<i.val<<" ";
    cout<<endl;
    for(auto i:r)
        cout<<i.val<<" ";
    cout<<endl;
        cout<<g[id].val<<" "<<g[id].l<<" "<<g[id].r<<" "<<g[id].ind<<endl;*/
        //cout<<cnt<<endl;
        answer = (answer + i*cnt)%mod;
        assert(answer>=0 && answer<mod);
        //cout<<cnt<<endl;
    }
    cout<<answer<<endl;


	return 0;

}
