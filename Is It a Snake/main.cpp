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
int n;
char pl[2][501];
int count(bool i)
{
    int cn =0;
    for(int j =0;j<n;j++)
    {
            if(pl[i][j] == '.' && pl[!i][j]=='.'&&cn)
            {
                break;
            }
            if(pl[i][j]=='#'&&pl[!i][j]=='#')
            {
                cn+=2;
                i=!i;
                continue;
            }
            if(pl[i][j]=='#' && pl[!i][j]=='.')
            {
                cn++;
                continue;
            }
            if(pl[i][j]=='.'&&pl[!i][j]=='#')
            {
                if(cn)
                    break;
                cn++;
                i=!i;
            }

        }
        return cn;
}
int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        cin>>n;
        int cnt=0;
        memset(pl,0,sizeof(pl));
        for(int i =0;i<2;i++)
        {
            for(int j =0;j<n;j++)
            {
                cin>>pl[i][j];
                if(pl[i][j]=='#')
                    cnt++;
            }
        }

        if(count(0) == cnt || count(1)==cnt)
            cout<<"yes\n";
        else
            cout<<"no\n";




    }

	return 0;

}
