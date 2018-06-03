#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e14;


bool valid(vector<ll> a)
{
    int n = a.size();
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            ll sum = 0;
            for(int k = i;k<=j;k++)
            {
                sum+=a[k];
            }
            if(sum <=0)
                return false;
        }
    }
    return true;
}

int main()
{

    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        vector<ll> a(n),ans(n);
        ll ansSum = INF;
        for(int i = 0;i<n;i++) cin >>a[i];
        for(int i = 0;i<1024;i++)
        {
            ll sum = 0;
            vector<ll> b;
            for(int j = 0;j<n;j++)
            {
                if((1<<j)&i)
                    b.push_back(-a[j]),sum-=a[j];
                else
                    b.push_back(a[j]), sum+=a[j];
            }
            if(ansSum > sum && valid(b))
                ansSum = sum,ans = b;
        }
        for(int i = 0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}
