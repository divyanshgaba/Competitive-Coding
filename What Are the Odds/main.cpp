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

int arr[500005];
int n;
int subCount(int arr[], int n, int k)
{

    int mod[k];
    memset(mod, 0, sizeof(mod));
    int result = 0;
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum = sum + arr[i];
        int idx = ((sum % k) + k) % k;
        if(mod[idx] >= 1) {
            if(idx == 0) {
                result = result + mod[idx] + 1;
            } else {
                result = result + mod[idx];
            }
        } else if(idx == 0 ){
            result = result + 1;
        }
        mod[idx]++;
    }

    return result;
}
int main()
{
	fast;
	cin>>n;
	int sum=0,od =0;
	int ev=0;
	for(int i =0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]%=2;
        sum+=arr[i];

        if(arr[i]%2==0)
            ev++;
        else
            od++;
    }
    ll ans=0;
    if(sum%2==0)
    {
        ans = subCount(arr,n,2)-od;
    }
    else
    {
        ans = n*(n+1)/2 - subCount(arr,n,2)-ev;
    }
    cout<<ans<<endl;
	return 0;

}
