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
const int N = 1e6;
int next_pos[N+11][26];
int main()
{
	fast;
	string s;
	cin>>s;
	s=" "+s;
	for(int i = 1;i<=s.length();i++)
    {
        for(int j = 0;j<26;j++)
        {
            next_pos[i+1][j] = next_pos[i][j];
        }
        next_pos[i+1][s[i]-97] = i;
    }

    int q;
    cin>>q;
    while(q--)
    {
        string p;
        cin>>p;
        int ind = s.length();
        int len = p.length();
        while(ind>0&&len>0)
        {
            ind = next_pos[ind][p[len-1]-97];
            if(ind!=0)
                len--;
        }
        cout<<p.length()-len<<endl;
    }
	return 0;

}
