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
bool valid(int val)
{
    int four,seven,other;
    four=seven=other=0;
    while(val)
    {
        if(val%10==4)
            four++;
        else if(val%10==7)
            seven++;
        else
            other++;
        val=val/10;
    }
    if(four == seven && other == 0)
        return true;
    return false;
}
int main()
{
	fast;
	int n;
	cin>>n;
	set<pair<int,string>> s;
	for(int i = 0;i<n;i++)
    {
        string k;
        int val;
        cin>>k>>val;
        if(valid(val))
            s.insert({val,k});
    }
    if(s.size()==0)
        cout<<-1<<endl;
    else
        cout<<(*s.begin()).S<<endl;
	return 0;

}
