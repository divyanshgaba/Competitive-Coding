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
const ll N=860280;
vector<ll> prime;
void sieve()
{
    bitset<N+1> isprime;
    isprime.reset();
    prime.PB(2);
    for(int i = 3;i<=sqrt(N);i+=2)
    {
        if(!isprime[i])
        {
            prime.PB(i);
            isprime[i]=true;
            for(int j = 2*i;j<=N;j+=i)
            {
                isprime[j]=true;
            }
        }
    }
    for(int i = sqrt(N)+1;i<N;i+=2)
    {
        if(i%2==0)
        {
            i++;
            continue;
        }
        if(!isprime[i])
        {
            prime.PB(i);
        }
    }
}
int main()
{
	fast;
	sieve();
	int test=1;
	//cin>>test;
	while(test--)
    {
        int q;
        cin>>q;
        while(q--)
        {
            int k;
            cin>>k;
            cout<<prime[k-1]<<endl;
        }

    }
	return 0;

}
