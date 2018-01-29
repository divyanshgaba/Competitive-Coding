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
	int a=1,b=1;
	unordered_map<int,bool> m;
	for(int i = 1;i<=n;i++)
    {
        b = a + b;
        a = b - a;
        m[a]=true;
    }
    for(int i = 1;i<=n;i++)
    {
        if(m[i])
            cout<<"O";
        else
            cout<<"o";
    }
    cout<<endl;
	return 0;

}
