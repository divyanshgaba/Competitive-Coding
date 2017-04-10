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

int space[11] = {6,2,5,5,4,5,6,3,7,6};
int used[11];
int mat[11][11];
int l,m;
int numdigit(int led,int places)
{
    if(places==-1)
        return 0;
    int cnt=0;
    for(int i =0;i<10;i++)
    {
        if(places == l-1 && i == 0 && l!=1)
            continue;
        if(used[i]==1)
            continue;
        used[i]=1;
        if(led>=space[i])
            cnt = max(cnt+numdigit(led-space[i],places-1)+1,cnt);
        used[i]=0;
    }
    l--;
    return cnt;
}
int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        memset(mat,0,sizeof(mat));
        cin>>l>>m;
        int led = m/7;
        memset(used,0,sizeof(used));
        //cout<<led<<endl;
        int digit = numdigit(led,l-1);
        cout<<digit<<endl;
    }
	return 0;

}
