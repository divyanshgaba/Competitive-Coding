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
int freq[11],freqb[11];
string a;
ll b;
ll num_b;
string ans;
bool poss(string a,int j)
{
    a.PB(char(j+'0'));
    for(int i = 0;i<10;i++)
    {
        for(int k = 0;k<freq[i];k++)
        {
            a.PB(char(i+'0'));
        }
        if(i==j)
            a.pop_back();
    }
    ll num_a = stoll(a);
    if(num_a<=b)
        return true;
    return false;
}
int main()
{
	cin>>a;
	cin>>b;
	for(int i = 0;i<a.size();i++)
    {
        if(isdigit(a[i]))
            freq[a[i]-'0']++;
    }
    for(int i = 0;i<a.size();i++)
    {
        for(int j = 9;j>=0;j--)
        {
            if(freq[j]<=0)
                continue;
            string temp = ans;
            if(poss(temp,j))
            {
                freq[j]--;
                ans.PB(char('0' + j));
                break;
            }
        }
    }
    cout<<ans<<endl;
	return 0;

}
