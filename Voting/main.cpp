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
	string s;
	cin>>s;
	queue<int> a,b;
    for(int i = 0;i<n;i++)
    {
        if (s[i] =='D')
            a.push(i);
        else
            b.push(i);
    }
    while(!a.empty() && !b.empty())
    {
        int d=a.front(),r=b.front();
        a.pop(),b.pop();
        if(d<r)
            a.push(d+n);
        else
            b.push(r+n);
    }
    if(a.empty())
        cout<<"R\n";
    else
        cout<<"D\n";



	return 0;

}
