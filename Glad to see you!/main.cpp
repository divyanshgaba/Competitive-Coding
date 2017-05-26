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

bool query(int a,int b)
{
    if(a==-1)
        return false;
    cout<<1<<" "<<a<<" "<<b<<endl;
    string s;
    cin>>s;
    return "TAK" == s;
}
int binsearch(int l, int h)
{
    if(l>h)
        return -1;
    while(l<h)
    {
        int m = (l+h)/2;
        if(query(m,m+1))
            h=m;
        else
            l=m+1;
    }
    return l;
}


int main()
{
	fast;
	int n,k;
	cin>>n>>k;
    //find initial point
    int x = binsearch(1,n);
    //search left of x
    int y = binsearch(1,x-1);

    // if y is farther than x is, meaning the point lies on right of x search in right of x
    if(!query(y,x))
        y = binsearch(x+1,n);
    cout<<2<<" "<<x<<" "<<y<<endl;


	return 0;

}
