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
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i = 0;i<n;i++)
        cin>>a[i];
    for(int i = 0;i<m;i++)
        cin>>b[i];
    int ans = 0;
    int t = 0;
    int i = 0,j=0;
    while(i<n&&j<m){
        if(t>=b[j]){
            t-=b[j++];
        }
        else
            t+=a[i++];
        if(t==0)
            ans++;
    }
    if(i!=n||j!=m)
        ans++;
    cout<<ans<<endl;
	return 0;

}
