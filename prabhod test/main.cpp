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

double distance(pair<int,int> a, pair<int,int> b)
{
    return sqrt(double(a.F-b.F)*double(a.F-b.F) + double(a.S-b.S)*double(a.S-b.S));
}
int all_set;
int n;
const double INF = 1e9;
pair<int,int> loc[16];
double memo[1048576];
double cur =INF;
int checker=0;
int counter =0;
double answer(int i,int mask)
{
    //cout<<i<<" "<<mask<<" "<<__builtin_popcount(mask)<<endl;
    if( __builtin_popcount(mask) == 2*n)
        return 0;
    if(i == 2*n)
        return INF;
    if(memo[mask]!=0)        return memo[mask];
    double temp = INF;
    if(mask&1<<i)        return answer(i+1,mask);
    mask|=1<<i;
    for(int j = 0;j<2*n;j++)
    {
        if(mask&(1<<j)) continue;
        temp=min(temp,distance(loc[i],loc[j]) + answer(i+1,mask|(1<<j)));
    }
    memo[mask]= temp;
    return temp;
}


int main()
{
	fast;
	cin>>n;
	for(int i =0;i<2*n;i++)
        cin>>loc[i].F>>loc[i].S;
    cout<<answer(0,0)<<endl;
    cout<<counter<<endl;
	return 0;

}
