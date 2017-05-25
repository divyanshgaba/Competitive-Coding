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
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i =1;i<=n;i++)
    {
        cin>>a[i];
    }
    int left[n],right[n];
    left[1]=1;
    right[n]=n;
    for(int i =2;i<=n;++i)
        left[i] = a[i]==a[i-1]?left[i-1]:i;
    for(int i =n-1;i>0;--i)
        right[i]= a[i]==a[i+1]?right[i+1]:i;
    for(int i =0;i<m;i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int mid = (r+l)/2;
        int ans = -1;
        int check = min(r,right[mid]) - max(l,left[mid]) + 1;
        if(check>=k)
            ans = a[mid];
        cout<<ans<<endl;
    }


	return 0;

}
