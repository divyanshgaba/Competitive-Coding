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
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i = 0;i<n;++i)
        cin>>a[i];
    int b[k];
    for(int i = 0;i<k;++i)
        cin>>b[i];
    sort(b,b+k,greater<int>());
    int j = 0;
    for(int i = 0;i<n;i++)
    {
        if(a[i] == 0)
            a[i] = b[j++];
    }
    bool ans = false;
    for(int i = 1;i<n;i++)
    {
        if(a[i]<a[i-1])
            ans = true;
    }
    if(ans)
        cout<<"Yes\n";
    else
        cout<<"No\n";

	return 0;

}
