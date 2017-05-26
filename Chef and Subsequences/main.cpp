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

int n;
long double k,a[35];
unordered_map<double,int> mp[35];
int solve(int i,double sum)
{
    if(i==n)
    {
        if(sum<=k)
        {
            return 1;
        }
        else
            return 0;
    }
    if(sum>k)
        return 0;
    if(mp[i].count(sum) > 0)
        return mp[i].at(sum);
    int temp = solve(i+1,sum) + solve(i+1,sum+a[i]);
    mp[i][sum]=temp;
    return temp;

}

int main()
{
	fast;
	cin>>n>>k;
	double sum =0;
	k = log10(k);
	for(int i =0;i<n;i++)
    {
        cin>>a[i];
        a[i]= log10(a[i]);
    }
    sort(a,a+n);
    int j =0;
    for(j =0;j<n;j++)
    {
        if(a[j] <= k)
            sum+=a[j];
        else
            break;
    }
    n = j;
    if(sum <= k)
    {
        cout<<round(pow(2,n)) -1 <<endl;
        return 0;
    }
	int ans =0;
	for(int i =0;i<n;i++)
    {
        ans+=(solve(i+1,a[i]));
    }
    cout<<ans<<endl;
	return 0;

}
