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

int a[101];
int n,k;
int mem[101][51];
int ans(int i, int val)
{
    if(i==n)
    {
        if(val==k)
            return 1;
        else
            return 0;
    }
    if(val > k)
        return 0;
    if(val==k)
        return 1;
    if(mem[i][val]!=0)
        return mem[i][val];
    int temp = ans(i+1,val+a[i]) + ans(i+1,val);
    mem[i][val] =temp;
    return temp;
}

int main()
{
	fast;
    cin>>n>>k;
    for(int i =0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<ans(0,0)<<endl;
	return 0;

}
