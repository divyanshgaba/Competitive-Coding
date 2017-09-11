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

const int N = 2147484646;
const int PN = 1e5;
bool factor[PN+1];
void prime()
{
    for(int i = 3;i<=PN;i+=2)
    {
        if(!factor[i])
        {
            for(int j = i+i;j<=PN;j+=i)
                factor[j] = true;
        }
    }
}

int digitSum(int n)
{
    int s = 0;
    while(n)
    {
        s += n%10;
        n /= 10;
    }
    return s;
}

bool ans(int n)
{
    int l = digitSum(n),r = 0;
    int lim = sqrt(n);
    for(int i = 2;i<=lim;i++)
    {
        if(!factor[i])
        {
            while(n%i==0)
            {
                r += digitSum(i);
                n /= i;
            }
        }
    }
    if(n>1)
        r+=digitSum(n);
    return r==l;
}

int main()
{
	fast;
    prime();
    int n;
    cin>>n;
    if(ans(n))
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
	return 0;

}
