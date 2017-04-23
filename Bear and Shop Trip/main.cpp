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
typedef pair<double,double> pi;
int n,k;
const int INF = 1e9;
int got;
bool marked[50];
pi loc[50];
int ing[50];
double dist[50][50];
double distance(int i,int j)
{
    if(dist[i][j]!=0)
        return dist[i][j];
    return dist[i][j] = sqrt(pow(loc[i].F - loc[j].F,2) + pow(loc[i].S - loc[j].S,2));
}
double ans[51][10000],hmm[51][10000];
//map<pair<int,int>,double> ans,hmm;
double solve(int,int);
double answer(int i,int poss)
{
    if(hmm[i][poss] > 0)
        return hmm[i][poss];
    double temp = INF;
    for(int j=1;j<=n;j++)
    {
        if(ing[j]|poss >poss&&!marked[j]){
                marked[j]=true;
            temp =min(temp,distance(i,j)+ solve(j,poss|ing[j]));
        marked[j]=false;
        }
    }
    return hmm[i][poss] = temp;
}

double solve(int i,int poss)
{
    if(i>n)
        return INF;
    double temp = INF;
    if(ans[i][poss] > 0)
        return ans[i][poss];
    if(poss == got)
        return distance(0,i);
    temp = min(temp,answer(i,poss));
    return ans[i][poss]=temp;
}

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        memset(marked,false,sizeof(marked));
        memset(dist,0,sizeof(dist));
        memset(loc,0,sizeof(loc));
        memset(ing,0,sizeof(ing));
        memset(ans,0,sizeof(ans));
        memset(hmm,0,sizeof(hmm));
        cin>>n>>k;

        for(int i =1;i<=n;i++)
            cin>>loc[i].F>>loc[i].S;
        int poss =0;
        for(int i =1;i<=n;i++)
        {
            string s;
            cin>>s;
            ing[i] = stoi(s,nullptr,2);
            poss|=ing[i];
        }
        got = pow(2,k)-1;
        if(poss != got)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<fixed<<setprecision(10)<<solve(0,0)<<endl;
    }
	return 0;

}
