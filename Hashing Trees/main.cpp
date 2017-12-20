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
	int h;
	cin>>h;
	int a[h+1];
	for(int i = 0;i<h+1;i++)
        cin>>a[i];
    bool ans = true;
    int it = -1;
    for(int i = 1;i<h+1;i++)
    {
        if(a[i-1]==1)
            continue;
        if(a[i]!=1)
        {
            it = i;
            ans = false;
            break;
        }
    }
    if(ans)
        cout<<"perfect\n";
    else
    {
        cout<<"ambiguous\n";
        int cnt = 0;
        for(int i = 0;i<h+1;i++)
        {
            for(int j=0;j<a[i];j++)
                cout<<cnt<<" ";
            cnt+=a[i];
        }
        cout<<endl;
        cnt = 0;
        vector<int> ans;
        for(int i = 0;i<it;i++)
        {
            for(int j=0;j<a[i];j++)
                ans.PB(cnt);
            cnt+=a[i];
        }
        int x = ans.size()-1;
        int y = ans.size();
        cnt+=a[it];
        ans.PB(x);
        for(int i = 0;i<a[it]-1;i++)
            ans.PB(y);
        for(int i = it+1;i<h+1;i++)
        {
            for(int j=0;j<a[i];j++)
                ans.PB(cnt);
            cnt+=a[i];
        }
        for(auto i:ans)
            cout<<i<<" ";
        cout<<endl;

    }
	return 0;

}
