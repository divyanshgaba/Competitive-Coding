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
	int test=1;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        int a[n+1];
        for(int i = 1;i<=n;i++) cin>>a[i];
        bool flag = 1;
        unordered_map<int,int> mp;
        flag = 0;
        for(int i = 1;i<=n;i++)
        {
            if(a[i]!=i)
            {
                flag = 1;
                break;
            }
        }
        for(int i = 1;i<=n;i++)
        {
            mp[a[i]]++;
            if(mp[a[i]]>1 || a[i]<1 || a[i]>n)
            {
                flag = 0;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"Ugly\n";
            continue;
        }
        else
        {
            cout<<"Beautiful\n";
            continue;
        }


    }
	return 0;

}
