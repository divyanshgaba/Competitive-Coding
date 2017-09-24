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
const int N = 1e5 + 7;
int arr[N];
int size[N];
void init(int n)
{
    for(int i = 1;i<=n;i++)
        arr[i]=i,size[i]=1;
}
int root(int i)
{
    while(arr[i]!=i)
    {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}
void myunion(int a,int b)
{
    int root_a = root(a);
    int root_b = root(b);
    if(root_a == root_b)
        return;
    if(size[root_a] >= size[root_b])
    {
        size[root_a] += size[root_b];
        arr[root_b] = root_a;
    }
    else
    {
        size[root_b] += size[root_a];
        arr[root_a] = root_b;
    }
}


int main()
{
	fast;
	int n,k,c;
	cin>>n>>k>>c;
	init(n);
	vector<pi> p(n);
	for(int i = 0;i<n;i++)
        cin>>p[i].F,p[i].S=i+1;
    sort(p.begin(),p.end());
    for(auto i = p.begin();i!=p.end()-1;i++)
    {
        auto e = *i;
        auto s = *(i+1);
        if(s.F-e.F <=k)
            myunion(s.S,e.S);
    }
    for(int i = 0;i<c;i++)
    {
        int l,r;
        cin>>l>>r;
        if(root(l) == root(r))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

	return 0;

}
