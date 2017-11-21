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
	cin>>test;
	while(test--)
    {
		int n,m;
		cin>>n>>m;
		vector<int> v(n,0);
		v[n-1]=m;
		int ans  = 0;
		while(v[0]!=m)
        {
            ans++;
            vector<int> a;
            for(int i = 0;i<n-1;i++)
            {
                if(v[i]<v[i+1])
                    a.PB(i),i++;
            }
            for(auto i:a)
                v[i]++;
            //for(int i = 0;i<n;i++)                cout<<v[i]<<" ";            cout<<"--"<<ans<<endl;
        }
        //cout<<(n-1) + (n>1?(m-1)*2:0)<<" ";
        cout<<ans<<endl;
    }
	return 0;

}
