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
		int n;
		cin>>n;
		vector<int> v,k;
		for(int i = 0;i<n;i++)
        {
            int a;
            cin>>a;
            v.PB(a);
            k.PB(a);
        }
        sort(k.begin(),k.end());
        int val = k[n-1] + k[n-2];
        double ans = 0;
        for(int i = 0;i<n-1;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(val == v[i]+v[j])
                    ans += 1;
            }
        }
        cout<<fixed<<setprecision(10)<<(ans/double(double(n*(n-1))/2))<<endl;
    }
	return 0;

}
