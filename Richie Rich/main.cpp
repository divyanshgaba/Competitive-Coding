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
bool vis[N];
bool palindrome(string s)
{
    int n = s.length();
    for(int i = 0;i<n/2;i++)
        if(s[i]!=s[n-i-1])
            return false;
    return true;
}
int main()
{
	fast;
    int n,k;
    cin>>n>>k;
    if(n==0)
        return 0;
    string s;
    cin>>s;
    for(int i = 0;i<n/2&&k>0;i++)
    {
        if(s[i]!=s[n-i-1])
        {
            if(s[i] < s[n-i-1])
                s[i] = s[n-i-1],k-=1,vis[i]=true;
            else
                s[n-i-1] = s[i],k-=1,vis[n-i-1]=true;
        }
    }
    for(int i = 0;i<n/2&&k>0;i++)
    {
        if(s[i]<'9')
        {
            if(vis[i] == true || vis[n-i-1] == true)
            {
                k-=1;
                s[i]='9',s[n-i-1]='9';
            }
            else if(k>=2)
            {
                k-=2;
                s[i]='9',s[n-i-1]='9';
            }
        }
    }
    if(k>0&&n%2!=0)
    {
        s[n/2]='9';
    }
    if(palindrome(s))
        cout<<s<<endl;
    else
        cout<<-1<<endl;
	return 0;

}
