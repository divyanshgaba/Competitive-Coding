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
	vector<int> v(256,-1);
	vector<bool> use(256,false);
	int a[n],b[n];
	for(int i = 0;i<n;i++)
        cin>>a[i];
    for(int i = 0;i<n;i++)
    {
        if(v[a[i]]!=-1)
        {
            b[i]=v[a[i]];
            for(int j = a[i];j>=v[a[i]];j--)
                use[j]=true;
            continue;
        }
        int j;
        for(j = max(0,a[i]-k+1);j<a[i];j++)
        {
            if(!use[j])
            {
                break;
            }
        }
        b[i]=j;
        for(int x = j;x<=a[i];x++)
            use[x]=true;
        for(int x = j;x<min(256,j+k);x++)
        {
            v[x]=j;
        }
    }
    for(int i =0;i<n;i++)
        cout<<b[i]<<" ";
    cout<<endl;
	return 0;

}
