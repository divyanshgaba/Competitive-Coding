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

int main()
{
    fast;
    int n;
    cin>>n;
    ll a[n+1];
    bool t = true;
    for(int i = 0;i<=n;i++) cin>>a[i],a[i]!=0?t=false:0;
    if(t)
        cout<<0<<" "<<0<<endl;
    else
    {
        bool sub = true;
        int i = n;
        for(i = n;i>=0;i--)
        {
            if(a[i]!=0)
            {
                if(a[i]<0)
                    sub = false;
                break;
            }
        }
        if(sub)
        {
            cout<<1<<" ";
            if(i&1)
                cout<<-1<<endl;
            else
                cout<<1<<endl;
        }
        else
        {
            cout<<-1<<" ";
            if(i&1)
                cout<<1<<endl;
            else
                cout<<-1<<endl;
        }
    }


    return 0;
}
