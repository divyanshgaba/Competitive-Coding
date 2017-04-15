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
        int n,k;
        cin>>n>>k;
        int c = 10;
        int flag =0;
        for(int i =1;i<k;i++)
        {
            c++;
            if(c%11==0)
                c++;
            if(c/100!=0)
            {
                flag =1;
                break;
            }
        }
        if(flag ==1)
            cout<<"-1\n";
        else
        {
            for(int i =0;i<n/2;i++)
                cout<<c;
            if(n%2!=0)
            {
                cout<<c/10;
            }
            cout<<"\n";
        }

    }
	return 0;

}
