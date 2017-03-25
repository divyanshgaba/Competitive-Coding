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

array<int,1000001> sur;
int main()
{
	fast;
	int n;
	cin>>n;
    REP(i,1,n)
    {
        int l,h,p,c,x;
        cin>>l>>h>>p>>c>>x;
        assert(x<100002);
        int height = *max_element(sur.begin()+x,sur.begin()+x+l);
        if(c==1)
        {
            height++;
            for(int j=x;j<x+l;j++)
                sur[j]=height;
            sur[x+p-1] +=h;
        }
        else
        {
            height= max(height,sur[x+p-1]+h);
            height++;
            for(int j=x;j<x+l;j++)
                sur[j]=height;
        }

    }
    cout<<*max_element(sur.begin(),sur.end())<<endl;
	return 0;

}
