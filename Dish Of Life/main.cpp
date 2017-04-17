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

int mem[100005];

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int n,k;
        cin>>n>>k;
        vi a[n];
        memset(mem,0,sizeof(mem));
        for(int i =0;i<n;i++)
        {
            int p;
            cin>>p;
            a[i].PB(p);
            for(int j =0;j<p;j++)
            {
                int x;
                cin>>x;
                a[i].PB(x-1);
                mem[x-1]++;
            }
        }
        int flag =0;
        for(int i =0;i<k;i++)
        {
            if(!mem[i])
            {
                flag =1;
                break;
            }
        }
        if (flag == 1)
        {
            cout<<"sad\n";
            continue;
        }
        for(int i =0;i<n;i++)
        {
            flag=1;
            for(int j =1;j<=a[i][0];j++)
            {
                if(mem[a[i][j]] == 1)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(flag ==1 )
            cout<<"some\n";
        else
            cout<<"all\n";

    }
	return 0;

}
