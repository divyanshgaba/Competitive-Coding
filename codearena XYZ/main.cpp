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
        vi a(n);
        for(int i =0;i<n;i++)
            cin>>a[i];
        sort(a.begin(),a.end());
        //a.erase(unique(a.begin(),a.end()),a.end());
        n = a.size();
        int cnt=0;
        for(int i =0;i<n;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                if(a[i]!=a[j])
                    if((a[i]+a[j])%2==0)
                        cnt++;
            }
        }
        cout<<cnt<<"\n";

    }
	return 0;

}
