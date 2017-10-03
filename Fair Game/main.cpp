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
	int t;
	cin>>t;
	int a[t];
	set<int> s;
    unordered_map<int,int> m;
	for(int i = 0;i<t;i++)
        cin>>a[i],s.insert(a[i]),m[a[i]]++;
    if(s.size()!=2)
        cout<<"NO\n";
    else
    {
        auto it = s.begin();
        auto jt = s.begin();
        advance(jt,1);
        //cout<<*it<<" "<<*jt<<"--- "<<endl;
        if(m[(*it)]==m[(*jt)])
            cout<<"YES\n",cout<<*it<<" "<<*jt<<endl;
        else
            cout<<"NO\n";

    }

	return 0;

}
