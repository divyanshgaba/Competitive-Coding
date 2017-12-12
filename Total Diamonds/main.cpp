/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
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
const int N = 1e6+1;
ll excess[2*N];
int cost(ll n)
{
    int ev = 0, od = 0;
    while(n)
    {
        int val = n%10;
        n/=10;
        if(val&1)
            od+=val;
        else
            ev+=val;
    }
    return abs(od-ev);
}
void init()
{
    for(int i = 1;i<2*N;i++)
        excess[i]=i-cost(i)+excess[i-1];
    for(int i = 1;i<2*N;i++)
        excess[i]+=excess[i-1];

}
int main()
{
	fast;
	init();
    int test = 1;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;
        cout<<(n*n*(n+1) - excess[2*n]) + 2*excess[n]<<endl;
    }
	return 0;
}
