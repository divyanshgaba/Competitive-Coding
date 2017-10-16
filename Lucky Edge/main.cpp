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
const int M = 1e3;
int m;
pi e[M];
int ans(int st,int en)
{
    if(st<0||en>=m)
        return 0;

}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		for(int i = 0;i<m;i++)
        {
            cin>>e[i].F>>e[i].S;
        }
        int f[m];
        for(int i = 0;i<m;i++)
        {
            f[i] = ans(i,i);
        }
    }
	return 0;

}
