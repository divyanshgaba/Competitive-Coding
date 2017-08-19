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

const int N = 1e5;
pair<int,int> a[2*N];
int n;

void build()
{
    for(int i = n-1;i>0;i--)
}

int main()
{
	fast;
    cin>>n;
    for(int i =n;i<2*n;i++) cin>>a[i].F,a[i].S = i-n;
    sort(a,a+n);

	return 0;

}
