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


int main()
{
	fast;
	int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        ll a[n];
        for(int i  =0;i<n;i++)
            cin>>a[i];
        int k;
        cin>>k;
        ll ele = a[k-1];
        sort(a,a+n);
        for(int i = 0;i<n;i++)
        {
            if(a[i] == ele)
            {
                cout<<i+1<<endl;
                break;
            }
        }

    }
	return 0;

}
