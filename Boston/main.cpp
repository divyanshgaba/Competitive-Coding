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
const int N = 5000;
bool isPrime[N];
vector<int> primes;

void sieve(){

    primes.PB(2);
    for(int i = 2;i<N;i+=2)
        isPrime[i]=true;
    for(int i = 3;i<N;i+=2){
        if(!isPrime[i]){
            primes.PB(i);
            for(int j = i*i;j<N;j+=i){
                isPrime[j]=true;
            }
        }
    }
}
int ds(int n){

    int res = 0;
    while(n){
        res+=n%10;
        n/=10;
    }
    return res;
}
int main()
{
    sieve();
    int n;
    cin>>n;
    int res = 0;
    int m = n;
    for(int i:primes){
        while(m%i==0){
            res+=ds(i);
            m/=i;
        }
    }
    if(m>1)
        res+=ds(m);
    cout<<m<<" "<<res<<endl;
    if(ds(n)==res){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }
	return 0;

}
