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
	cin>>test;
	while(test--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        map<string,list<pair<int,string>>> mt;
        for(int i = 1;i<=n;i++)
        {
            string h,c;
            cin>>h>>c;
            if(mt[c].size()<k)
                mt[c].PB(MP(-i,h));
        }
        priority_queue<pair<int,string>> p;
        int cnt = 0;
        priority_queue<pair<int,string>> ans;
        while(k)
        {
            for(auto i=mt.begin();i!=mt.end();i++)
            {
                if((*i).S.size()!=0)
                    p.push((*i).S.front()), (*i).S.pop_front();
            }
            k--;
            while(cnt<m&&!p.empty())
            {
                ans.push(p.top());
                p.pop();
                cnt++;
            }
            if(cnt == m)
                break;

        }
        if(cnt<m)
            cout<<"Impossible\n\n";
        else
        {
            while(!ans.empty())
                cout<<ans.top().S<<endl,ans.pop();
            cout<<endl;
        }

    }
	return 0;

}
