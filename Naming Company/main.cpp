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
	string ol,ig;
	cin>>ol>>ig;
	sort(ol.begin(),ol.end());
	sort(ig.rbegin(),ig.rend());
	//cout<<ol<<" "<<ig<<endl;
	int n = ig.length();
	int x = 0,a=0,b=0,y=0;
	int st=0,en = n-1;
	string ans ="";
	for(int i =0;i<n;i++)
        ans.PB('?');
	for(int i =0;i<n;i++)
    {
        if(i%2==0)
        {
            if(ol[x] < ig[y])
                ans[st++] = ol[x++];
            else
                ans[en--] = ol[n/2 + n%2 - a++-1  ];
        }
        else
        {
            if(ig[y] > ol[x])
                ans[st++]=ig[y++];
            else
                ans[en--] = ig[n/2 - b++-1 ];
        }
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
	return 0;

}
