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

int mem[4];
int main()
{
	fast;
	int n;
	cin>>n;
	int a[n];
	int sum =0;
	for(int i =0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
            a[i]*=-1;
        a[i] %= 3;

        mem[a[i]]++;
        sum+=a[i];
    }
    if(sum%3 == 0)
    {
        cout<<0;
        return 0;
    }
    if(sum%3 == 1)
    {
        if(mem[1]>0)
        {
            cout<<1;
            return 0;
        }
        if(mem[2]>0)
        {
            cout<<2;
            return 0;
        }
    }
    if(sum%3 ==2)
    {
        if(mem[2]>0)
        {
            cout<<1;
            return 0;
        }
        if(mem[1]>0)
        {
            cout<<2;
            return 0;
        }
    }


	return 0;

}
