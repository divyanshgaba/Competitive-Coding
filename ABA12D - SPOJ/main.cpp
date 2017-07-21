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
const int N = 1e6+7;
int a[2*N+1];
bool isprime(int n)
{
    if(n<=1)
        return false;
    for(int i = 2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
void build()
{
    for(int i = N-1;i >0;i--) a[i] = a[i<<1]+a[i<<1|1];
}
int query(int l,int r)
{
    int res = 0;
    for(l+=N,r+=N;l<r;l>>=1,r>>=1)
    {
        if(l&1)
            res+=a[l++];
        if(r&1)
            res+=a[--r];
    }
    return res;
}
void pre()
{
    a[2+N] = 1;
    for(int i = 3;i<=N;i++)
    {
        int sum = 0;
        int s = sqrt(i);
        if(s*s == i)
        {
            for(int j = 1;j<=sqrt(i);j++)
            {
                if(i%j==0)
                {
                    if(i/j == j)
                        sum+=j;
                    else
                        sum+=(j+i/j);
                }
            }
        if(sum!=0&&isprime(sum))
            a[i+N] =1;
        }
    }
    build();
}

int main()
{
	fast;
	pre();
	int test=1;
	cin>>test;
	while(test--)
    {
		int a,b;
		cin>>a>>b;
		cout<<query(a,b+1)<<endl;
    }
	return 0;

}
