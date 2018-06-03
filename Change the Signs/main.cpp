#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;
const ll INF = 1e16+55;


vector<ll> answer(vector<ll> a)
{
    int n = a.size();
    ll ans[n][2][2],minsum[n][2][2];
    ans[0][0][0] = minsum[0][0][0] = a[0];
    ans[0][0][1] = minsum[0][0][1] = a[0];
    ans[0][1][0] = minsum[0][1][0] = -a[0];
    ans[0][1][1] = minsum[0][1][1] = -a[0];
    for(int i = 1;i<n;i++)
    {

        ans[i][0][0] = ans[i][0][1] = ans[i][1][0] = ans[i][1][1] = INF;
        minsum[i][0][0] = minsum[i][0][1] = minsum[i][1][0] = minsum[i][1][1] = -INF;


        if(minsum[i-1][0][0] + a[i] > 0 )
        {
            if(ans[i][0][0] > ans[i-1][0][0] + a[i])
                ans[i][0][0] = ans[i-1][0][0] + a[i], minsum[i][0][0] = a[i];
        }


        if(minsum[i-1][0][1] + a[i] > 0 )
        {
            if(ans[i][0][0] > ans[i-1][0][1] + a[i])
                ans[i][0][0] = ans[i-1][0][1] + a[i], minsum[i][0][0] = a[i];
            else if(ans[i][0][0] == ans[i-1][0][1] + a[i])
                minsum[i][0][0] = max(minsum[i][0][0],minsum[i-1][0][1]+a[i]);
        }


        if(minsum[i-1][1][0] + a[i] > 0  && -a[i-1] + a[i] > 0)
        {
            if(ans[i][0][1] > ans[i-1][1][0] + a[i])
            {
                ans[i][0][1] = ans[i-1][1][0] + a[i];
                minsum[i][0][1] = min(a[i],minsum[i-1][1][0] + a[i]);
            }
        }

        if(minsum[i-1][0][0] - a[i] > 0 && a[i-1] - a[i] > 0)
        {
            if(ans[i][1][0] > ans[i-1][0][0] - a[i])
                ans[i][1][0] = ans[i-1][0][0] - a[i], minsum[i][1][0] = min(-a[i],minsum[i-1][0][0] - a[i]);
        }


        if(minsum[i-1][0][1] - a[i] > 0 && a[i-1] - a[i] > 0)
        {
            if(ans[i][1][0] > ans[i-1][0][1] - a[i])
                ans[i][1][0] = ans[i-1][0][1] - a[i], minsum[i][1][0] = min(-a[i],minsum[i-1][0][1] - a[i]);
        }



    }
    vector<ll> b(n);
    ll val = min(ans[n-1][0][0],ans[n-1][0][1]);
    val = min(val, ans[n-1][1][0]);
    if(val == ans[n-1][0][0])
    {
        b[n-1] =1;
        b[n-2] =1;
    }
    else if(val == ans[n-1][0][1])
    {
        b[n-1]=1;
        b[n-2]=-1;
    }
    else
    {
        b[n-1] =-1;
        b[n-2]=1;
    }
    for(int i = n-3;i>=0;i-=2)
    {
        if(b[i+2] == 1 && b[i+1] == 1)
        {
            ll val = ans[i+2][0][0] - a[i+1] - a[i+2];
            if(val == ans[i][0][0])
            {
                b[i]=1;
                if(i-1 >= 0)
                    b[i-1] =1;
            }
            else if(val == ans[i][0][1])
            {
                b[i]=1;
                if(i-1 >= 0)
                    b[i-1]=-1;
            }
            else
            {
                b[i] =-1;
                if(i-1 >= 0)
                    b[i-1]=1;
            }
        }
        else if(b[i+2] == -1 && b[i+1] == 1)
        {
            ll val = ans[i+2][1][0] - a[i+1] + a[i+2];
            if(val == ans[i][0][0])
            {
                b[i]=1;
                if(i-1 >= 0)
                    b[i-1] =1;
            }
            else if(val == ans[i][0][1])
            {
                b[i]=1;
                if(i-1 >= 0)
                    b[i-1]=-1;
            }
            else
            {
                b[i] =-1;
                if(i-1 >= 0)
                    b[i-1]=1;
            }
        }
        else if(b[i+2] == 1 && b[i+1] == -1)
        {
            ll val = ans[i+2][0][1] + a[i+1] - a[i+2];
            if(val == ans[i][0][0])
            {
                b[i]=1;
                if(i-1 >= 0)
                    b[i-1] =1;
            }
            else if(val == ans[i][0][1])
            {
                b[i]=1;
                if(i-1 >= 0)
                    b[i-1]=-1;
            }
            else
            {
                b[i] =-1;
                if(i-1 >= 0)
                    b[i-1]=1;
            }
        }
        else
            assert(false);
    }
    vector<ll> out;
    for(int i = 0;i<n;i++)
        out.push_back(a[i]*b[i]);
    return out;

}
ll sum(const vector<ll> &a)
{
    ll s = 0;
    for(auto i:a)
        s+=i;
    return s;
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        vector<ll> a(n);
        for(int i = 0;i<n;i++)
        {
            cin>>a[i];
        }
        vector<ll> ansA = answer(a);
        reverse(a.begin(),a.end());
        vector<ll> ansB = answer(a);
        if(sum(ansA) < sum(ansB))
        {
            for(auto i:ansA)
                cout<<i<<" ";
            cout<<endl;
        }
        else
        {
            reverse(ansB.begin(),ansB.end());
            for(auto i:ansB)
                cout<<i<<" ";
            cout<<endl;
        }
    }
	return 0;

}
