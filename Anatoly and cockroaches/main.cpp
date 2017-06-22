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

bool a[100001];
int n;
string s;
int solve(bool t)
{
    int b=0,r=0;
    for(int i = 0;i<n;i++,t=!t)
    {
        if(a[i] != t)
        {
            if(s[i] == 'b')
                b++;
            else
                r++;
        }

    }
    return max(b,r);

}

int main()
{
	fast;
	cin>>n;
	cin>>s;
	for(int i = 0;i<n;i++)
        a[i] = s[i]=='b';
	cout<<min(solve(true),solve(false))<<endl;
	return 0;

}
