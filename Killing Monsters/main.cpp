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
	int n;
	cin>>n;
	int h[n];
	unordered_map<int,int> m;
	for(int i = 0;i<n;i++)
    {
        cin>>h[i];
        m[i]=h[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        vector<unordered_map<int,int>::iterator> v;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(((*it).F&x) == (*it).F)
            {
                (*it).S -= y;
                if((*it).S <=0)
                    v.PB(it);
            }
        }
        for(auto i:v)
            m.erase(i);
        cout<<m.size()<<endl;
    }
	return 0;

}
