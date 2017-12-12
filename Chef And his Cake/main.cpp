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
		char cake[n][m];
		for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                cin>>cake[i][j];
		int cost1=0;
		bool t = true;
		for(int i = 0;i<n;i++)
        {
            bool f = t;
            for(int j = 0;j<m;j++)
            {
                if(cake[i][j]=='R')
                {
                    if(!f)
                        cost1+=5;

                }
                else
                {
                    if(f)
                        cost1+=3;
                }
                //cout<<f<<" ";
                f=!f;
            }
            //cout<<endl;
            t=!t;
        }
        int cost2=0;
		t = false;
		for(int i = 0;i<n;i++)
        {
            bool f = t;
            for(int j = 0;j<m;j++)
            {
                if(cake[i][j]=='R')
                {
                    if(!f)
                        cost2+=5;

                }
                else
                {
                    if(f)
                        cost2+=3;
                }
                //cout<<f<<" ";
                f=!f;

            }
            //cout<<endl;
            t=!t;

        }
        cout<<min(cost1,cost2)<<endl;
    }
	return 0;

}
