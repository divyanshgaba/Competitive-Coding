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

int x[4];
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        int a[n];
        x[0]=x[1]=x[2]=x[3]=0;
		for(int i = 0;i<n;i++) cin>>a[i],x[a[i]%4]+=1;
		int ans = 0;
		ans += min(x[1],x[3]),x[1]-=ans,x[3]-=ans;
		ans += x[2]/2,x[2]=x[2]%2;
		if(x[1])
        {
            ans+=(x[1]/4)*3;
            x[1]%=4;
            if(x[2])
            {
                if(x[1]==2)
                    ans+=2,x[1]=x[2]=0;
            }
        }
        else if(x[3])
        {
            if(x[2])
            {
                if(x[3]>=2)
                    ans+=2,x[3]-=2,x[2]=0;
            }
            ans+=(x[3]/4)*3;
            x[3]%=4;
        }
        if(x[1]||x[2]||x[3])
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
	return 0;

}
