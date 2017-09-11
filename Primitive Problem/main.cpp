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

const int N = 1e9;
const int PN = sqrt(N);
int factor[PN+1];
void prime()
{
    for(int i = 1;i<=PN;i++)
        factor[i] = i;
    for(int i = 2;i<=PN;i+=2)
        factor[i]=2;
    for(int i = 3;i<=PN;i+=2)
    {
        if(factor[i]==i)
        {
            for(int j = i+i;j<=PN;j+=2)
                factor[j] = i;
        }
    }
}



int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {

    }
	return 0;

}
