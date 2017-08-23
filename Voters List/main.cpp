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
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int x;
    map<int,int> m;
    for(int i = 0;i<n1+n2+n3;i++)
        cin>>x,m[x]++;
    for(auto i:m)
        if(i.S >=2)
            cout<<i.F<<endl;
	return 0;

}
