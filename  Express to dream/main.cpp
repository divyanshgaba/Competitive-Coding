/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
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
	int a[n],b[n];
	for(int i = 0;i<n;i++)
        cin>>a[i];
    for(int i = 0;i<n;i++)
        cin>>b[i];
    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        if(a[i] != b[i])
            cnt++;
    }
    if(cnt == 1)
    {
        if(n == 2)
        {
            if(a[0]==b[0])
            {
                if(a[0]==1)
                    cout<<2<<" ";
                else
                    cout<<1<<endl;
            }
            cout<<b[1]<<" ";
        }
        else
        {
            for(int i = 0;i<n;i++)
            {
                if(a[i] == b[i])
                    cout<<a[i]<<" ";
                else
                {
                    for(int j = 1;j<=n;j++)
                    {
                        if(j!=a[i] && b[i]!=j)
                            cout<<j<<" ";
                    }
                }
            }
        }
    }
    else
    {
        for(int i = 0;i<n;i++)
        {
            if(a[i]==b[i])
                cout<<a[i]<<" ";
            else
            {
                if(cnt%2!=0)
                    cout<<a[i]<<" ";
                else
                    cout<<b[i]<<" ";
                cnt--;
            }
        }
    }
	return 0;

}
