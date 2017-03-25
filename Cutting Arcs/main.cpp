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

int arc[3630];

int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        memset(arc,0,sizeof(arc));
        for(int i =0;i<n;i++)
        {
            double st,et;
            cin>>st>>et;
            int s = st*10;
            int e = et*10;
            int dif;
            if(s>e)
                dif = 3600 -abs(s-e);
            else
                dif = abs(s-e);
            for(int j = 0;j<=dif;j++)
            {
                arc[(s+j)%3600]++;
            }

        }
        cout<<*max_element(arc,arc+3610)<<endl;
    }
	return 0;

}
