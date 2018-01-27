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

bool lucky(int h,int m)
{
    while(h)
    {
        if(h%10 == 7)
            return true;
        h/=10;
    }
    while(m)
    {
        if(m%10 == 7)
            return true;
        m/=10;
    }
    return false;
}

int main()
{
	fast;
	int x;
	cin>>x;
	int h,m;
	cin>>h>>m;
	int cnt = 0;
	while(!lucky(h,m))
    {
        m-=x;
        if(m<0)
        {
            m+=60;
            h-=1;
            if(h<0)
                h += 24;
        }
        cnt++;
        //cout<<h<<" "<<m<<endl;
    }
    cout<<cnt<<endl;
	return 0;

}
