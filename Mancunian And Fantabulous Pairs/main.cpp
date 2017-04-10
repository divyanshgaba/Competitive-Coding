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
    int a[n+1];
    for(int i =1;i<=n;i++)
        cin>>a[i];
    pi f,s;
    int ans =0;
    f= make_pair(2,a[2]);
    s = make_pair(1,a[1]);
    if(s.S<f.S)
        ans++;
    for(int i =3;i<=n;i++)
    {
        if(f.S<a[i])
        {
            s=f;
            f =make_pair(i,a[i]);
            ans=ans+f.F-s.F;

        }
        else if(s.S<a[i])
        {
            f=s;
            s= make_pair(i,a[i]);

        }
    }
    cout<<ans;
	return 0;

}
