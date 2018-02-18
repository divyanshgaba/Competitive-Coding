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
	int a[n];
	for(int i = 0;i<n;i++)
        cin>>a[i];
    string s;
    cin>>s;
    for(int i = 0;i<n-1;i++)
    {
        if(s[i]=='1')
        {
            int cnt = 1;
            for(int j = i+1;j<n-1;j++)
            {
                if(s[j]=='1')
                    cnt++;
                else
                    break;
            }
            //cout<<cnt<<endl;
            sort(a+i,a+i+cnt+1);
            i+=(cnt-1);

        }
    }
    bool ans = true;
    for(int i= 1;i<=n;i++)
    {
        //cout<<a[i-1]<<" ";
        if(a[i-1]!=i)
        {
            ans = false;
            //break;
        }
    }
    if(ans)
        cout<<"YES\n";
    else
        cout<<"NO\n";
	return 0;

}
