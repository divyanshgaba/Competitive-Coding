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
	//fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int w[n+1];
        int l = 0;
        for(int i = 0;i<n;i++)
        {
            if(a[i] == b[i])
                l++;
        }
        for(int i = 0;i<=n;i++)
            cin>>w[i];
        if(l == n)
            cout<<w[n]<<endl;
        else
            cout<<*max_element(w,w+l+1)<<endl;
    }
	return 0;

}
