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
bool beautiful(int n)
{
    int ans = 0;
    for(int i = 0;i<32;i++)
    {
        if((1<<i)&n)
        {
            ans = i;
            break;
        }
    }
    int temp = ans;
    for(int i = ans;i<32;i++)
    {
        if(!((1<<i)&n))
        {
            temp = i;
            break;
        }
    }
    for(int i = temp+1;i<32;i++)
    {
        if((1<<i)&n)
            return false;
    }
    //cout<<temp-ans <<" "<<temp<<" "<<ans<<" "<<n<<endl;
    if(temp - ans - 1 == ans)
        return true;
    return false;
}
int main()
{
	fast;
    int n;
    cin>>n;
    for(int i = n;i>=1;i--)
    {
        if(n%i==0&&beautiful(i))
        {
            cout<<i<<endl;
            break;
        }
    }
	return 0;

}
