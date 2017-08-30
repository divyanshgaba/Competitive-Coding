/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
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
const ll INF = 1e18;

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int n,k;
		cin>>n>>k;
		vecotr<ll> dog(n);
		for(int i = 0;i<n;i++) cin>>dog[i];
		set<ll> s(dog.begin(),dog.end());
		dog.assign(s.begin(),s.end());
		int p = dog.size()-k;
		if(p<=0)
            cout<<0<<endl;
        else
        {
            priority_queue<ll, vector<ll>, greater<ll>> pq;
            for(int i = 0;i<dog.size()-1;i++)
            {
                pq.push(abs(dog[i]-dog[i+1]));
            }
            int ans = 0;
            while(p>0)
            {
                ans += pq.top();
                pq.pop();
                p--;
            }
            cout<<ans<<endl;

        }
    }
	return 0;

}
