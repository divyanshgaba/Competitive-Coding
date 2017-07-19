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

int main()
{
	fast;
	int test=1;
	//cin>>test;
	while(test--)
    {
		int n,k;
		cin>>n>>k;
		priority_queue<ll,vector<ll>,greater<ll>> q;
		for(int i = 0; i<n;i++)
        {
            int a;
            cin>>a;
            q.push(a);
        }
        int ans = 0;
        while(q.size()>=2&&q.top() <k)
        {
            int a=q.top();q.pop();int b=q.top(); q.pop();
            int c = a + 2*b;
            q.push(c);
            ans++;
        }
        if(q.top()<k)
        {
            cout<<-1<<endl;
        }
        else
            cout<<ans<<endl;



    }
	return 0;

}
