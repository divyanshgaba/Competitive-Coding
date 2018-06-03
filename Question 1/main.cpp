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
	int x=1;
	cin>>x;
	while(x--)
    {
		int y;
		cin>>y;
		int i = 1;
		int ans = -1;
		int temp = 1;
		while(((temp&1)||((ans=temp)&1)) && (y/i))
        {
            int digit = (y/i)%10;
            temp = digit;
            i*=10;
        }
        cout<<ans<<endl;
    }
	return 0;

}
