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

int job[1002];
int main()
{
	fast;
	int test;
    cin>>test;
    while(test--)
    {
        int n,m;
        cin>>n>>m;
        memset(job,0,sizeof(job));
        REP(i,1,m)
        {
            int x;
            cin>>x;
            job[x]=1;
        }
        int x =0,y=0;
        vi chef,mate;
        REP(i,1,n)
        {
            if(x==y && job[i]==0)
            {
                chef.PB(i);
                x++;
            }
            else if(job[i]==0)
            {
                mate.PB(i);
                y++;
            }

        }
        sort(chef.begin(),chef.end());
        sort(mate.begin(),mate.end());
        for(auto it : chef)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        for(auto it: mate)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
	return 0;

}
