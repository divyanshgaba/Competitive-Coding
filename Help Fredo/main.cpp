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
	long double l=1,a[n];
	for(int i =0;i<n;i++)
        cin>>a[i],l*=a[i];
    l = pow(l,1.0/n);
    if(n%2==0)
        cout<<-(long long)(ceil(l));
    else
        cout<<(long long)(ceil(l));
	return 0;

}
