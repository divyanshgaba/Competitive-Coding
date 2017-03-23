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
#define lim 100003

bool isprime(int n)
{
    if(n==2)
        return true;
    if (n==1)
        return false;
    for(int i =2;i<=sqrt(n);i++)
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
	while(test--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        n = n%2!=0?n:n+1;
        int ans;
        for(int i =n;i<=lim;i++)
        {
            if(isprime(i))
            {
                ans = i;
                break;
            }
        }
        cout<<ans*2<<endl;
    }
	return 0;

}
