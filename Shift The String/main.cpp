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
string a,b;
int n;
int arr[1000001];
void computeLPS()
{
    arr[0]=0;
    int j=0;
    for(int i =1;i<n;)
    {
        if(b[i] == b[j])
        {
            arr[i] = j+1;
            j++;
            i++;
        }
        else
        {
            if(j!=0)
            {
                j = arr[j-1];

            }
            else
            {
                arr[i]=0;
                i++;
            }
        }
    }
}

int main()
{
	fast;
	cin>>n;
	cin>>a>>b;
	b=b+b;
    computeLPS();
    int i =0;
    int j =0;
    int ans=0;
    int best =0;
    int res=0;
    int len =2*n;
    while(i<len)
    {
        if(a[j] == b[i])
        {
            i++;
            j++;
            best++;
        }
        if(best > res)
        {
            res = best;
            ans = i-j;
        }
        if(j==n||i==len)
            break;
        if(a[j] != b[i])
        {
            best=0;
            if(j!=0)
                j=arr[j-1];
            else
                i++;
        }

    }
    cout<<ans;
	return 0;

}
