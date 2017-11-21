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
	cin>>n>>m>>k;
	int a[n][n];
	a[0][0]=m;
	for(int i = 1;i<n;i++)
        a[i][i] = a[i-1][i-1]+k;
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            a[i][j] = a[i][j-1]-1;
            a[j][i] = a[j-1][i]-1;
        }
    }
    for(int i = 0;i<n;i++,cout<<endl)
        for(int j = 0;j<n;j++)
            cout<<a[i][j]<<" ";
	return 0;

}
