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
vector<ll> primes(5000000);
const ll N = 86028121;
bool isprime[N+10];

void sieve()
{
    isprime[0] = isprime[1] = true;
    int lim = sqrt(N)+1;
    for(int i = 3;i<=lim;i+=2)
    {
        if(!isprime[i])
        {
            for(int j = i+i;j<=N;j+=i)
                isprime[j]= true;
        }
    }
    int idx = 1;
    primes[0]= 2;
    for(int i = 3;i<=N;i+=2)
        if(!isprime[i])
            primes[idx++] = i;
}

int main()
{
	int test=1;
	sieve();
	//cin>>test;
	while(test--)
    {
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int k;
            scanf("%d",&k);
            printf("%d\n",primes[k-1]);
        }

    }
	return 0;

}
