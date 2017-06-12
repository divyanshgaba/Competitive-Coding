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
	int test;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        string s,k;
        cin>>s;
        cin>>k;
        vi top,bot;
        int fl =0;
        for(int i =0;i<n;i++)
        {
            if(s[i]=='*')
            {
                top.PB(i);
            }
            if(k[i] == '*')
            {
                bot.PB(i);
            }

        }
        /*for(auto i: top)
            cout<<i<<" ";
        cout<<endl;
        for(auto i:bot)
            cout<<i<<" ";
        cout<<endl;
        cout<<top.size()<<" "<<bot.size()<<" "<<endl;*/
        if(top.size() == 0 || bot.size() == 0)
        {
            int ans = max(top.size(),bot.size());
            ans = max(ans-1,0);
            cout<<ans<<endl;
            continue;
        }
        vi walls;
        int cn = 1;
        int ts = top.size()-1;
        int bs = bot.size()-1;
        int idt =0,idb=0;
        int to = max(top[ts],bot[bs]);
        while(idt < ts && idb < bs)
        {
            if(top[idt] < bot[idb])
            {
                if(top[idt+1] <= bot[idb])
                {
                    walls.PB(top[idt]);
                    cn++;
                    idt++;
                }
                else
                {
                    walls.PB(bot[idb]);
                    cn++;
                    idt++;
                    idb++;
                }
            }
            else
            {
                if(bot[idb+1] <= top[idt])
                {
                    walls.PB(bot[idb]);
                    cn++;
                    idb++;
                }
                else
                {
                    walls.PB(top[idt]);
                    cn++;
                    idb++;
                    idt++;
                }
            }

        }
        cn+=(ts-idt);
        cn+=(bs-idb);
        cout<<cn<<endl;
    }
	return 0;

}
