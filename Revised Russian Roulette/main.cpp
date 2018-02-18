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
    int min=0,max=0;
	for(int i = 0;i<n;i++)
    {
        if(a[i]==1)
            min++,i+=1;

    }
    for(int i = n-1;i>=0;i--)
    {
        if(a[i]==1)
            max++;
    }
    cout<<min<<" "<<max<<endl;
	return 0;

}
