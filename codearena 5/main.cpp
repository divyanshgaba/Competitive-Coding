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

const int MAX = 1e6 +7;
vi primes;
bool ifpri[MAX];
int sieve()
{
    memset(ifpri,true,sizeof(ifpri));
    ifpri[0]=ifpri[1]=false;
    for(int i =2;i<=MAX;i++)
    {
        if(ifpri[i])
        {
            for(int j = i+i;j<=MAX;j+=i)
            {
                ifpri[j]=false;

            }
        }
    }
    for(int i =2;i<=MAX;i++)
        if(ifpri[i])
            primes.PB(i);
}

double g(int c)
{
    double ans = c;
    for(auto i:primes)
    {
        int cnt =0;
        while(c%i==0)
        {
            cnt++;
            c/=i;
        }
        if(cnt>0)
        {
            double temp = i;
            ans*=(1-1/temp);
        }

    }
    return ans;
}

int main()
{
	fast;
	int test;
	cin>>test;
	sieve();
	while(test--)
    {
        int n;
        cin>>n;
        cout<<g(n)<<endl;
    }
	return 0;

}
