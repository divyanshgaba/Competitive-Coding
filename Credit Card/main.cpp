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
#define REP(i,a,b) for (int64_t i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int64_t> vi;
typedef pair<int64_t,int64_t> pi;

int main()
{
	fast;
    int64_t n,d;
    cin>>n>>d;
    int64_t a[n];
    for(int64_t i = 0;i<n;i++)
        cin>>a[i];
    int64_t bal = 0;
    int64_t ans = 0;
    bool poss = true;
    int64_t curover = 0;
    for(int64_t i = 0;i<n;i++)
    {
        bal += a[i];
        if(bal > d)
        {
            if(curover >= bal-d)
            {
                curover = curover-(bal-d);
                bal = d;
            }
            else
            {
                poss = false;
                break;
            }
        }
        if(a[i] == 0)
        {
            if(bal >= 0)
                continue;
            bal = d;
            curover = d;
            ans++;
        }
    }
    if(poss)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
	return 0;

}
