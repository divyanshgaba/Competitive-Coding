#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define SIZE 1000007

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int a[SIZE];
int s[4*SIZE];
int rangemax(int ql,int qh,int l,int h,int pos)
{
    if(ql<=l && qh>=h)
        return s[pos];
    if(ql>h || qh<l)
        return -1;
    int mid = (l+h)/2;
    return max(rangemax(ql,qh,l,mid,2*pos+1),rangemax(ql,qh,mid+1,h,2*pos+2));
}

void constree(int low,int high,int pos)
{
    if(low == high)
    {
        s[pos] = a[low];
        return;
    }
    int mid = (low+high)/2;
    constree(low,mid,2*pos+1);
    constree(mid+1,high,2*pos+2);
    s[pos] = max(s[2*pos+1],s[2*pos+2]);
}

int main()
{
	fast;
	int n;
	cin>>n;
	for(int i =0;i<n;i++)
        cin>>a[i];
	constree(0,n-1,0);
	int q;
	cin>>q;
	for(int i =0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        cout<<rangemax(x,y,0,n-1,0)<<endl;
    }
	return 0;

}
