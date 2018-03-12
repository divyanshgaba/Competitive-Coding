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
	string s;
	cin>>s;
	int k = 0;
	string ans = "abcdefghijklmnopqrstuvwxyz";
	for(int i = 0,n=s.length();k<26&&i<n;i++)
    {
        if(s[i]>ans[k])
            continue;
        s[i]=ans[k++];
    }
    if(k==26)
        cout<<s<<endl;
	else
        cout<<-1<<endl;
	return 0;

}
