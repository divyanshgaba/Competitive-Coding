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

vi pr;
bool prime[32001];
int sieve()
{
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i =2;i<=32000;i++)
    {
        if(prime[i])
        {
            for(int j =2*i;j<=32000;j+=i)
                prime[j]=false;
        }
    }
    for(int i=2;i<=32000;i++)
        if(prime[i])
            pr.PB(i);
}
bool ifprime(int n)
{
    if(n<=32000)
        return prime[n];
    for(auto i:pr)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
	fast;
	int test;
	cin>>test;
	sieve();
	while(test--)
    {
        int a,b;
        cin>>a>>b;
        for(int i = a;i<=b;i++)
        {
            if(ifprime(i))
                cout<<i<<endl;
        }
        cout<<endl;
    }
	return 0;

}
