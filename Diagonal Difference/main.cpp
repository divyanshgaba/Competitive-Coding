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
		int n;
		cin>>n;
		int a[n][n];
		for(int i = 0;i<n;i++)
            for(int j =0;j<n;j++)
                cin>>a[i][j];
        int sum1, sum2;
        sum1=sum2=0;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
                sum1 += i==j?a[i][j]:0, i+j == n-1? sum2+=a[i][j]:0;
        cout<<abs(sum1-sum2)<<endl;

    }
	return 0;

}
