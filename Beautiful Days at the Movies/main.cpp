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
        int a,n;
        cin>>a>>n;
        int arr[n+1];
        for(int i =1;i<=n;i++)
            cin>>arr[i];
        int ans = 0;
        int flag = 0;
        for(int i =1;i<=n;i++)
        {
            a--;
            if(arr[i] == 1)
                a+=3;
            if(a==0)
            {
                ans = i;
                flag = 1;
                break;
            }
        }
        if(flag == 1 && ans <=n )
        {
            cout<<"No "<<ans<<endl;
        }
        else
        {
            cout<<"Yes "<<a<<endl;
        }

    }


	return 0;

}
