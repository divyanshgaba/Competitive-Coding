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
int l,n,x,y;
int a[101];
int min_ans = 1e9,max_ans=-1e9;
bool visited[101][10001];
void answer(int i,int p)
{
    if(p > y || p < x)
        return;
    if(visited[i][p])
        return;
    visited[i][p]=true;
    min_ans = min(min_ans,p);
    max_ans = max(max_ans,p);
    if(i==n)
        return;
    answer(i+1,p-a[i]),answer(i+1,p+a[i]);
}
int main()
{
	fast;
	cin>>l>>n>>x>>y;
	for(int i = 0;i<n;i++) cin>>a[i];
	int q;
	cin>>q;
	max_ans= min_ans = l;
	answer(0,l);
	//cout<<min_ans<<" "<<max_ans<<endl;
	while(q--)
    {
        char a;
        int x;
        cin>>a>>x;
        if(a == '>' && max_ans > x)
            cout<<"YES\n";
        else if(a == '<' && min_ans < x)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
	return 0;

}
