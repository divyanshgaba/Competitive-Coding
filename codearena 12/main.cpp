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
	int k;
	cin>>k;
	int a[k];
	int sw[k][k];
	for(int i =0;i<k;i++)
        cin>>a[i];
    for(int i =0;i<k;i++)
    {
        for(int j =0;j<k;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='Y')
                sw[i][j]=1;
            else
                sw[i][j]=0;
        }
    }

    for(int i =0;i<k;i++)
        cout<<a[i]<<" ";
    cout<<endl;
	return 0;

}
