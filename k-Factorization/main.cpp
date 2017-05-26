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

int main()
{
	fast;
	int n,k;
	cin>>n>>k;
	vi div;
	for(int i =2;i<=sqrt(n)+1;i++)
    {
        while(n%i ==0)
        {
            div.PB(i);
            n/=i;
        }
    }
    if(n>2)
        div.PB(n);
    if(div.size() < k )
        cout<<"-1\n";
    else
    {
        int prod = div[0];
        int len = div.size();
        for(int i =1;i<len-k+1;i++)
            prod*=div[i];
        cout<<prod<<" ";
        for(int i = len-k+1;i<len;i++)
            cout<<div[i]<<" ";
        cout<<endl;
    }

	return 0;

}
