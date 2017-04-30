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
	int n;
	cin>>n;
	int a[n];
	for(int i =0;i<n;i++)
        cin>>a[i];
    int cnt =0;
    for(int i =0;i<n-2;i++)
    {
        if((a[i] < a[i+1] && a[i+1] < a[i+2])||((a[i] > a[i+1] && a[i+1] > a[i+2])))
            cnt++;
    }
    cout<<cnt<<endl;
	return 0;

}
