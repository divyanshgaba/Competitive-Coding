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
const int N = 1e3;
int arr[N];
int s[N];
void init(int n)
{
    for(int i = 0;i<n;i++)
    {
        arr[i]=i;
        s[i]=1;
    }
}
int r(int x)
{
    while(x!=arr[x])
    {
        arr[x]=arr[arr[x]];
        x=arr[x];
    }
    return x;
}
bool connect(int a,int b)
{
    int r_a=r(a),r_b=r(b);
    if(r_a==r_b)
        return true;
    if(s[r_a]<s[r_b])
    {
        s[r_b]+=s[r_a];
        arr[r_a]=arr[r_b];
    }
    else
    {
        s[r_a]+=s[r_b];
        arr[r_b]=arr[r_a];
    }
    return false;
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int n,m;
		cin>>n>>m;
		init(n);
		bool ans = false;
		for(int i = 0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            ans = ans|connect(a,b);
        }
        if(ans)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;

    }
	return 0;

}
