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
	int s;
	cin>>s;
	while(s--)
    {
        int n;
        cin>>n;
        int a[n+1];
        for(int i =1;i<=n;i++)
            cin>>a[i];
        if(n%2 ==0)
        {
            cout<<"no\n";
            continue;
        }
        int mid = n/2;
        bool ans = true;
        if(a[1]!=1 || a[n] !=1)
        {
            cout<<"no\n";
            continue;
        }
        for(int i =1;i<n;i++)
        {
            if(i<=mid)
            {
                if(a[i+1]-a[i]!=1)
                {
                    ans = false;
                    break;
                }
            }
            else
            {
                if(a[i]-a[i+1]!=1)
                {
                    ans = false;
                    break;
                }
            }
        }

        if(ans)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
	return 0;

}
