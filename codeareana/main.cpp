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
    int test;
    cin>>test;
    while(test--)
    {
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        int b = a[1];
        if(a[2] == 0)
        {
            cout<<0<<endl;
            continue;
        }
        //int c = a[2];
        if(b<a[2])
        cout<<2*b+1<<endl;
        else
            cout<<2*b<<endl;

    }

	return 0;

}
