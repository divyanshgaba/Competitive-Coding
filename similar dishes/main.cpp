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
        map<string,int> s;
        string a[4];
        for(int i =0;i<4;i++)
        {
            cin>>a[i];
            s[a[i]]=1;
        }
        int cnt=0;
        for(int i =0;i<4;i++)
        {
            cin>>a[i];
            if(s.count(a[i])!=0)
            {
                cnt++;
            }
        }
        if(cnt>=2)
            cout<<"similar";
        else
            cout<<"dissimilar";
        cout<<"\n";

    }
	return 0;

}
