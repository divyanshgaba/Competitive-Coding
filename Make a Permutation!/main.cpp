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
const int N = 2e5;
bool vis[N+1];
int main()
{
	fast;
	int n;
	cin>>n;
	int a[n];
	unordered_map<int,int> m;
	for(int i = 0;i<n;i++)
        cin>>a[i],m[a[i]]++;
    set<int> s;
    vector<int> b;
    for(int i = 1;i<=n;i++)
    {
        if(m[i]==0)
        {
            b.PB(i);
        }
    }
    int p = 0;
    for(int i = 0;i<n&&p<b.size();i++)
    {
        if(m[a[i]]<=1)
            continue;
        if(a[i]>b[p] || vis[a[i]])
            m[a[i]]--,a[i]=b[p++];
        else
            vis[a[i]]=true;

    }
    cout<<p<<endl;
    for(int i = 0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

	return 0;

}
