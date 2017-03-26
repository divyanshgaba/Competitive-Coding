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
	ll array[200000];
    ll m;
    ll n;
    ll i;
    ll index;
    cin>>n;
    array[0]=1;
    m=1;
    i=1;
    while(i<=n)
    {
        ll temp=0;
        for(index=0;index<m;index++)
        {
            ll x= 2*array[index] +temp;
            array[index]=x%10;
            temp=x/10;
        }
        while(temp!=0)
        {
            array[m++]=temp%10;
            temp/=10;
        }
        i++;
    }
    cout<<array[m-1]-1;
    for(i=m-2;i>=0;i--)
    {
        printf("%d",array[i]);
    }

}
