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
int p[151][151];

int main()
{
	fast;
	int n;
	cin>>n;;
	for(int i = 0;i<=n;i++)
    {
        p[i][i] = 1;
    }
    for(int i = 2;i<=n;i++)
    {
        p[i][0] = p[i-2][0];
        for(int j = 0;j<i;j++)
        {
            p[i][j+1] = p[i-1][j] + p[i-2][j+1];
            if(abs(p[i][j+1])>1)
                p[i][j+1]=p[i-1][j]-p[i-2][j+1];
        }
    }
    cout<<n<<endl;
    for(int i = 0;i<=n;i++)
        cout<<p[n][i]<<" ";
    cout<<endl;
    cout<<n-1<<endl;
    for(int i = 0;i<n;i++)
        cout<<p[n-1][i]<<" ";
    cout<<endl;
	return 0;

}
