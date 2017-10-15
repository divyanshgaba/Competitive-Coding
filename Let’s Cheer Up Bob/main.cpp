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
int grid[3][3];
bool won()
{
    for(int i = 0;i<3;i++)
    {
        if(grid[i][0]==grid[i][1]&&grid[i][1]==grid[i][2]&&grid[i][2]==1)
            return true;
        if(grid[0][i]==grid[1][i]&&grid[1][i]==grid[2][i]&&grid[2][i]==1)
            return true;
    }
    if(grid[0][0]==grid[1][1]&&grid[1][1]==grid[2][2]&&grid[2][2]==1)
        return true;
    if(grid[0][2]==grid[1][1]&&grid[1][1]==grid[2][0]&&grid[2][0]==1)
        return true;
    return false;
}
vector<pi> win[11111];
int ans(int m)
{
    if(won())
        return m;

}
int main()
{
	fast;
	int n = 9;
	vector<pi> moves;
	for(int i = 0;i<n;i++)
    {
        pi a;
        cin>>a.F>>a.S;
        moves.PB(a);
    }


	return 0;

}
