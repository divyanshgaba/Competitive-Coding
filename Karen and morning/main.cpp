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

int palindrome(int t)
{
    //int temp = t;
    if(t/1000 != t%10 || (t/100)%10 != (t/10)%10)
        return false;
    return true;
}

int to_24(int t)
{
    int f = (t/60)%24;
    int s = (t%60);
    int time = f*100 + s;
    //cout<<time<<endl;
    return time;
}

int main()
{
	fast;
	int f,s;
	char ch;
	cin>>f>>ch>>s;
	int time = 60*f + s;
	for(int i = 0;i<1440;i++)
    {
        if(palindrome(to_24(time+i)))
        {
            cout<<i<<endl;
            break;
        }
    }
	return 0;

}
