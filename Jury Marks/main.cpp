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
	//cin>>test;
	while(test--)
    {
        unordered_map<int,int> mp,ex;
        int n,k;
        cin>>k>>n;
        int a[k];
        for(int i = 0;i<k;i++)
        {
            cin>>a[i];
            if(i)
                a[i]+=a[i-1];
            cout<<a[i]<<" ";
        }
        cout<<endl;
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>b[i],ex[b[i]]=1;
        int ans =0;
        for(int i = 0;i<k;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int ele = b[j] - a[i];

            }
        }
        cout<<ans<<endl;

    }
	return 0;

}
