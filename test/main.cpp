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
	ULL t; cin>>t;
	while(t--)
	{
        string s; cin>>s;
        LL x,y; cin>>x>>y;
        LL n=s.length();
        LL a=0,b=0;
        string ans;
        F(i,0,n)
        {
            if(s[i]=='a') a++;
            else b++;
        }
        while(true)
        {
            if((a==0)&&(b==0)) break;
            if(a>b)
            {
                if(b==0)
                {
                    LL m=ans.length();
                    if(ans[m-1]=='a')
                    {
                        ans.append("*");
                    }
                    F(i,0,min(x,a)) ans.append("a");
                    if(x<a) ans.append("");
                    a-=min(x,a);
                    if(a==0) break;
                }
                else
                {
                    LL m=ans.length();
                    if(ans[m-1]=='a')
                    {
                        ans.append("b");
                        b-=1;
                    }
                    F(i,0,min(x,a)) ans.append("a");
                    a-=min(x,a);
                }
            }
            if(a==b)
            {
                LL m=ans.length();
                if(ans[m-1]=='a') F(i,0,a) ans.append("ba");
                else F(i,0,a) ans.append("ab");
                break;
            }
            if(a<b)
            {
                if(a==0)
                {
                    LL m=ans.length();
                    if(ans[m-1]=='b')
                    {ans.append("*"); }
                    F(i,0,min(b,y)) ans.append("b");
                    if(y<b) ans.append("");
                    b-=min(b,y);
                    if(b==0) break;
                }
                else
                {
                    LL m=ans.length();
                    if(ans[m-1]=='b')
                    {ans.append("a"); a-=1;}
                    F(i,0,min(b,y)) ans.append("b");
                    b-=min(b,y);
                }
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}
