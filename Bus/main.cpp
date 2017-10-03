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
	int a,b,f,k;
	cin>>a>>b>>f>>k;
	if(k==1)
    {
        if(b<max(f,a-f))
            cout<<-1<<endl;
        else
        {
            int ans = 0;
            b-=f;
            if(b<(a-f))
                ans++;
            cout<<ans<<endl;
        }
    }
    else if(k==2)
    {
        if(b<max(f,2*(a-f)))
        {
            cout<<-1<<endl;
        }
        else
        {
            int ans = 0;
            int cap = b-f;
            if(cap<2*(a-f))
                cap=b,ans++;
            cap-=2*(a-f);
            if(cap<f)
                cap=b,ans++;
            cout<<ans<<endl;
        }
    }
	else if(max(2*(a-f),2*(f))>b)
    {
        cout<<-1<<endl;
    }
    else
    {
        int ans = 0;
        int cap = b-f;
        bool forw = true;
        for(int i = 0;i<k;i++)
        {
            if(forw)
            {
                if(i==k-1)
                {
                    if(cap<(a-f))
                        cap=b,ans++;
                    cap-=(a-f);
                }
                else
                {
                    if(cap<2*(a-f))
                        cap=b,ans++;
                    cap-=2*(a-f);
                }
                forw = false;
            }
            else
            {
                if(i==k-1)
                {
                    if(cap<f)
                        cap=b,ans++;
                    cap-=f;
                }
                else
                {
                    if(cap<2*f)
                        cap=b,ans++;
                    cap-=2*f;
                }
                forw = true;
            }
        }
        cout<<ans<<endl;
    }
	return 0;

}
