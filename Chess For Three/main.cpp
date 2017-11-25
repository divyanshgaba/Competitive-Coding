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
    int p1 = 1,p2 = 2;
    int s = 3;
    int a[n];
    for(int i = 0;i<n;i++)
        cin>>a[i];
    bool ans = true;
    for(int i = 0;i<n;i++)
    {
        if(a[i] != p1 && a[i]!= p2)
        {
            ans = false;
            break;
        }
        if(a[i] == p1)
        {
            swap(p2,s);
        }
        else
        {
            swap(p1,s);
        }
    }
    if(ans)
        cout<<"YES\n";
    else
        cout<<"NO\n";
	return 0;

}
