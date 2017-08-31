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
const int X = 1e4+1;
int A[X];
int main()
{
	fast;
    int n;
    cin>>n;
    int a;
    for(int i = 0;i<n;i++) cin>>a,A[a]++;
    int m;
    cin>>m;
    int b;
    for(int i = 0;i<m;i++) cin>>b,A[b]--;
    for(int i = 1;i<X;i++)
        if(A[i] != 0)
            cout<<i<<" ";
    cout<<endl;
	return 0;

}
