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
const int N = 1e5;
const int rtN = sqrt(N)+1;
struct Q
{
    int i;
    int l,r;
    int val;
};
int a[N];
bool comp(Q a, Q b)
{
    if(a.val!=b.val)
        return a.val>b.val;
    return a.r>b.r;
}
int main()
{
	fast;
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++) cin>>a[i];
	Q q[m];
	for(int i = 0;i<m;i++)
    {
        cin>>q[i].l>>q[i].r;
        q[i].l--,q[i].r--;
        q[i].i = i;
        q[i].val = q[i].l/rtN;
    }
    sort(q,q+m,comp);
    int answer[m];
    int ans = 0;
    int l = 0,r = 0;
    unordered_map<int,int> hold;
    hold[a[0]]++;
    if(hold[a[0]]==a[0])
        ans++;
    for(int i = 0;i<m;i++)
    {
        while(l<q[i].l)
        {
            if(hold[a[l]] == a[l])
                ans--;
            hold[a[l]]--;
            if(hold[a[l]] == a[l])
                ans++;
            l++;
        }
        while(l>q[i].l)
        {
            l--;
            if(hold[a[l]] == a[l])
                ans--;
            hold[a[l]]++;
            if(hold[a[l]]==a[l])
                ans++;
        }
        while(r<q[i].r)
        {
            r++;
            if(hold[a[r]]==a[r])
                ans--;
            hold[a[r]]++;
            if(hold[a[r]]==a[r])
                ans++;
        }
        while(r>q[i].r)
        {
            if(hold[a[r]]==a[r])
                ans--;
            hold[a[r]]--;
            if(hold[a[r]]==a[r])
                ans++;
            r--;
        }
        answer[q[i].i]=ans;
    }
    for(int i = 0;i<m;i++)cout<<answer[i]<<endl;
	return 0;

}
