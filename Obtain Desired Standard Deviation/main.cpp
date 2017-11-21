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
		double n,st;
		cin>>n>>st;
		if(n==1&&st==0)
            cout<<0<<endl;
        else if(n==1 && st!=0)
            cout<<-1<<endl;
        else
        {
            int N = n;
            for(int i = 0;i<n-1;i++)
                cout<<0<<" ";
            cout<<fixed<<setprecision(10)<<(n*st)/sqrt(n-1)<<endl;
        }


    }
	return 0;

}
