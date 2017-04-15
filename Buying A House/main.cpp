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
	int n,m,k;
    cin>>n>>m>>k;
    int a[n];
    int house =1e9;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
            continue;
        if(a[i]<=k)
        {
            if(abs(house-m) > abs(i-m))
                house = i;
        }
    }
    cout<<abs(house-m+1)*10<<endl;

	return 0;

}
