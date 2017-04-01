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
bool prime[1000001];
void ans(int n)
{

    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}

int main()
{
	fast;
	int test;
	ans(1000001);
	prime[0]=prime[1]=false;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        if(prime[n])
            cout<<"True\n";
        else
            cout<<"False\n";
    }
	return 0;

}
