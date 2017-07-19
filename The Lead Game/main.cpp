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

void solve()
{
    int n;
    cin>>n;
    ll winner = 0;
    ll answer = 0;
    ll score[3];
    score[1]=score[2] = 0;
    while(n--)
    {
        ll a,b;
        cin>>a>>b;
        score[1]+=a,score[2]+=b;
        if(answer < llabs(score[1] - score[2]))
        {
            answer = llabs(score[1]-score[2]);
            if(score[1] > score[2])
                winner = 1;
            else
                winner = 2;
        }
    }
    cout<<winner<<" "<<answer<<endl;

}

int main()
{
	fast;
	int test=1;
	//cin>>test;
	while(test--)
    {
        solve();
    }
	return 0;

}
