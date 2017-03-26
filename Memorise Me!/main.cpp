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

int b[1001];

int main()
{
	fast;
	int n;
	cin>>n;
	for(int i =0;i<n;i++)
    {
        int x;
        cin>>x;
        b[x]++;
    }
	int q;
	cin>>q;
	for(int i =0;i<q;i++)
    {
        int x;
        cin>>x;
        if(b[x]!=0)
            cout<<b[x]<<endl;
        else
            cout<<"NOT PRESENT\n";
    }
	return 0;

}
