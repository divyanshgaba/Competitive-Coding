#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
	int test;
    int n,p,q;
    cin>>n>>p>>q;
    int ali[p],bob[q];
    for(int i =0;i<p;i++)
    {
        cin>>ali[i];
        ali[i]%=n;
    }
    for(int i =0;i<q;i++)
    {
        cin>>bob[i];
        bob[i]%=n;
    }
    int flag;
    int ans=1;
    for(int k =1;k<=n;k++){
            flag =0;
        for(int i =0;i<p;i++)
        {
            for(int j =0;j<q;j++)
            {
                if((k+ali[i]+bob[j])%n ==0)
                {
                    flag =1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(flag==0)
        {
            ans =k;
            break;
        }
    }
    cout<<ans<<endl;
	return 0;

}
