#include <bits/stdc++.h>
#define F(i,p,n) for(LL i=p; i<n; i++)
#define loop(i, n) for(LL i=0; i<n; i++)
#define fast   ios_base::sync_with_stdio(0); cin.tie(0)
#define dd double
#define mem(a, v) memset(a, v, sizeof(a))
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;
int main()
{
	fast;
	ULL t; cin>>t;
	while(t--)
	{
        string s; cin>>s;
        LL n=s.length();
        int b[10];
        mem(b,0);
        F(i,0,n)
        {
            b[s[i]-48]++;
        }
        F(i,0,10)
        {
            cout<<b[i];
        }
        F(i,6,10)
        {
            if(b[i]>0)
            {
                cout<<"i am here1 "<<i<<" ";
                b[i]--;
                if((i>6)&&(i<9))
                {
                    cout<<"i am here2 ";
                    F(j,0,10)
                    {
                        if(b[j]>0)
                        {
                            cout<<(j+(10*i))<<"      "<<j<<" ";
                            //b[j]--;
                            cout<<(j+(10*i));
                        }
                    }
                }
                if(i==6)
                {
                    F(j,5,10)
                    {
                        if(b[j]>0)
                        {
                            //b[j]--;
                            cout<<(j+(10*i));
                        }
                    }
                }
                if(i==9) cout<<"Z";
            }
            b[i]++;
        }
        cout<<endl;

	}
	return 0;
}
