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
ll n,x;
vector<string> poss;
map<pair<int,pair<string,ll>>,bool> m;
void answer(int i,string s,ll sum)
{
    //cout<<i<<" "<<s<<" "<<sum<<endl;
    if(i>n)
    {
        if(sum == 0)
        {
            poss.PB(s);
        }
        return;
    }
    auto j = MP(i,MP(s,sum));
    if(m[j])
        return;
    m[j]=true;
    if(i==x)
        answer(i+1,s+"2",sum);
    else
        answer(i+1,s+"0",sum-i),answer(i+1,s+"1",sum+i);
}
void solve(ll a, ll b)
{
    x=a,n=b;
    m.clear();
    poss.clear();
    answer(1,"",0);
    for(auto i:poss)
        cout<<i<<endl;
    cout<<"-------"<<endl;
}
bool zero(ll x,ll n)
{
    bool l = false;
    bool r = false;
    if((n-x)%4==0)
        r = true;
    if((x-1)%4==0 || x%4==0)
        l = true;
    return l&&r;

}
ll left_zero(ll x)
{
    if((x-1)%4==0 || x%4==0)
        return true;
    return false;
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        ll x,n;
        cin>>x>>n;
        //solve(x,n);
        //if(x < n-x+1)            x = n-x+1,sw = true;
        int ans[n+1];
        memset(ans,0,sizeof(ans));
        ans[x]=2;
        int ind;
        bool exist = true;
        // both size zeros
        if(zero(x,n))
        {
            int a[]={0,1,1,0};
            ind = 3;
            for(int i = x-1;i>=0;i--)
            {
                ans[i] = a[ind--];
                if(ind<0)
                    ind = 3;
            }
            ind = 0;
            for(int i = x+1;i<=n;i++)
            {
                ans[i]=a[ind++];
                if(ind>3)
                    ind = 0;
            }
        }
        else
        {
            int a[] = {0,1,1,0};
            int t = (n-x)%4;
            if(t == 0)
            {
                //if(left_zero(x-1))                    assert(1!=0);
                exist = false;
            }
            else if(t == 1)
            {
                bool fl = true;
                if(x>=5 && left_zero(x-5))
                {
                    fl = false;
                    ans[x-1]=ans[x-2]=1;
                    ans[x-3]=0;
                    ans[x-4]=1;
                    ans[x-5]=0;
                    ind = 3;
                    for(int i = x-6;i>=0;i--)
                    {
                        ans[i]=a[ind--];
                        if(ind<0)
                            ind = 3;
                    }
                    ans[x+1]=0;
                    ind = 0;
                    for(int i = x+2;i<=n;i++)
                    {
                        ans[i]=a[ind++];
                        if(ind>3)
                            ind = 0;
                    }
                }
                if(n-x>=5 && fl && left_zero(x-1))
                {
                    ans[x+1]=1;
                    ans[x+2]=1;
                    ans[x+3]=0;
                    ans[x+4]=1;
                    ans[x+5]=0;
                    ind = 0;
                    for(int i = x+6;i<=n;i++)
                    {
                        ans[i]=a[ind++];
                        if(ind>3)
                            ind = 0;
                    }
                    ans[x-1]=0;
                    ind = 3;
                    for(int i = x-2;i>=0;i--)
                    {
                        ans[i]=a[ind--];
                        if(ind<0)
                            ind = 3;
                    }

                }

            }
            else if(t==2)
            {

                if(x>=2)
                {
                    ans[x-1]=1;
                    ans[x-2]=0;
                    ind = 3;
                    for(int i = x-3;i>=0;i--)
                    {
                        ans[i]=a[ind--];
                        if(ind<0)
                            ind = 3;
                    }
                    ans[x+1] = 1;
                    ans[x+2] = 0;
                    ind = 0;
                    for(int i = x+3;i<=n;i++)
                    {
                        ans[i]=a[ind++];
                        if(ind>3)
                            ind = 0;
                    }
                }
            }
            else if(t == 3)
            {
                bool fl = true;
                if(x>=3&&left_zero(x-3))
                {
                    fl = false;
                    ans[x-1]=0;
                    ans[x-2]=0;
                    ans[x-3]=1;
                    ind = 3;
                    for(int i = x-4;i>=0;i--)
                    {
                        ans[i]=a[ind--];
                        if(ind<0)
                            ind = 3;
                    }
                    ans[x+1]=1;
                    ans[x+2]=1;
                    ans[x+3]=0;
                    ind = 0;
                    for(int i = x+4;i<=n;i++)
                    {
                        ans[i]=a[ind++];
                        if(ind>3)
                            ind = 0;
                    }
                }


            }
        }
        ll sum = 0;
        for(int i = 1;i<=n;i++)
        {
            if(ans[i]==0)
                sum+=i;
            else if(ans[i]==1)
                sum-=i;
        }
        if(sum==0)
        {

            for(int i = 1;i<=n;i++)
                cout<<ans[i];
            cout<<endl;
        }
        else
            cout<<"impossible"<<endl;
    }
	return 0;

}
