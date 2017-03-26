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
	int n,k;
	cin>>n>>k;
	int a[n+1];
	for(int i =1;i<=n;i++)
    {
        cin>>a[i];
    }
    vi b;
    for(int i =1;i<=n;i++)
    {
        if(a[i]<0)
        {
            b.PB(i);
            if(i!=n)
            {
                a[i+1]*=-1;
            }
        }
    }
    cout<<b.size()<<endl;
    for(auto it:b)
        cout<<it<<" ";

	return 0;

}
