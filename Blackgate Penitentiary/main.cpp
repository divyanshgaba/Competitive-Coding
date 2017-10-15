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
	vector<string> v[251];
	for(int i = 0;i<n;i++)
    {
        string s;
        int h;
        cin>>s>>h;
        v[h].PB(s);
    }
    int c = 1;
    for(int i = 120;i<251;i++)
    {
        if(v[i].size()==0)
            continue;
        sort(v[i].begin(),v[i].end());
        int st = c,en = c;
        for(auto j:v[i])
            cout<<j<<" ",en++;
        cout<<st<<" "<<en-1<<endl;
        c=en;
    }
	return 0;

}
