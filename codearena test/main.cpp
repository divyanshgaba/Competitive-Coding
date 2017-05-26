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
const int mod = 1e9+7;
const int r5=400000003;
const int r7 =142857144;


vector<pair<int,pi> > pot;

const int MAXL = 910;

int answer[MAXL];
int tmp[MAXL];
int ml;

bool cmp(pair<int,pi> a,pair<int,pi> b)
{
    if(a.F != b.F)
        return a.F<b.F;
    return false;
}

int searc(int val)
{
    int l =0;
    int r = pot.size()-1;
    while(l<=r)
    {
        int m = (l+r)/2;
        if(pot[m].F==val)
            return m;
        if(pot[m].F<val)
            l=m+1;
        else
            r=m-1;
    }
    return -1;
}

void ab()
{
    ll twop = 1;
    for(int a=0;a/3 <700;a++)
    {
        ll threep = twop;
        for(int b = 0;a/3+b/2<700;b++)
        {
            pot.PB(MP(threep,MP(a,b)));
            threep = (threep*3)%mod;
        }
        twop = (twop*2)%mod;
    }
    sort(pot.begin(),pot.end(),cmp);
}
bool lesser(int l)
{
    for (int i=l - 1; i >= 0; i--)
		if (answer[i] != tmp[i])
			return tmp[i] < answer[i];
	return false;
}

void winner(int a,int b, int c,int d)
{
    if(a/3+b/2+c+d >900)
        return;
    int len=0;
    while(b>=2)
    {
        tmp[len++]=9;
        b-=2;
    }
    while(a>=3)
        tmp[len++]=8,a-=3;
    while(d>=1)
        tmp[len++]=7,d--;
    while(a>=1&&b>=1)
        tmp[len++]=6,a--,b--;
    while(c>=1)
        tmp[len++]=5,c--;
    while(a>=2)
        tmp[len++]=4,a-=2;
    while(b>=1)
        tmp[len++]=3,b--;
    while(a>=1)
        tmp[len++]=2,a--;
    if(ml > len || (ml==len && lesser(ml)))
    {
        for (int i=0; i < len; i++)
			answer[i] = tmp[i];
		ml = len;
    }
}

void ans(int n)
{
    if(n==0)
    {
        cout<<"10\n";
        return;
    }
    if(n==1)
    {
        cout<<"1\n";
        return ;
    }
    ml = 1000;
    ll fivep = n;
    for(int c = 0;c<700;c++)
    {
        ll sevenp = fivep;
        for(int d = 0;d+c<700;d++)
        {
            int i = searc(sevenp);
            if(i!=-1)
            {
                winner(pot[i].S.F,pot[i].S.S,c,d);
            }
            sevenp = (sevenp *r7)%mod;
        }
        fivep = (fivep *r5)%mod;
    }
    for(int i =ml-1;i>=0;i--)
        cout<<answer[i];
    cout<<endl;
}

int main()
{
	fast;
	ab();
    int n;
    cin>>n;
    ans(n);
	return 0;

}
