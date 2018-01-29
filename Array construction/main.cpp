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
	srand(time(NULL));
	int n,m;
	cin>>n>>m;
	int c[n][n];
	priority_queue<pair<int,pair<int,int>>>p;
	for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
        cin>>c[i][j],p.push(MP(c[i][j],MP(i,j)));
    int a[n];
    memset(a,0,sizeof(a));
    if(m>=n)
    {
        for(int i = 0;i<n;i++)
            a[i]=m/n;
        m=m%n;
    }
    while(m)
    {
        int i = rand()%n;
        a[i]++;
        m--;
    }
    for(int i = 0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

	return 0;

}
