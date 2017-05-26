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
	int test;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i =0;i<n;i++)
            cin>>a[i];
        int flag =0;
        for(int i =0;i<n-1;i++)
        {
            if(a[i]>a[i+1] && abs(a[i]-a[i+1]) ==1 )
                swap(a[i],a[i+1]);
        }
        for(int i =0;i<n;i++)
        {
            if(a[i]!=i)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"Yes\n";
        else
            cout<<"No\n";

    }
	return 0;

}
