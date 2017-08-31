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
    int n,m,k;
    cin>>n>>m>>k

    unordered_map<int, vector<pair<int,int>>> mp;
    for(int i = 0;i<k;i++)
    {
        int r,c1,c2;
        cin>>r>>c1>>c2;
        mp[r].push_back(make_pair(c1,c2));
    }
    for(auto i : mp)
    {
        sort(i.second.begin(),i.second.end());
        int cov = 0;
        for(auto j: i.second)
        {

        }
    }
	return 0;

}
