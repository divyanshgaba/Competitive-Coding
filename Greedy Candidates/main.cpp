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
const int N = 1e3;
const int M = 1e3;
ll minSalary[N];
ll offeredSalary[M], maxJobOffers[M];
int qual[N][M];
bool gotJob[N];
bool gaveJob[M];

void init()
{
    memset(minSalary,0,sizeof(minSalary));
    memset(offeredSalary,0,sizeof(offeredSalary));
    memset(maxJobOffers,0,sizeof(maxJobOffers));
    memset(qual,0,sizeof(qual));
    memset(gotJob,false,sizeof(gotJob));
    memset(gaveJob,false,sizeof(gaveJob));
}

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
        init();
		int n,m;
		cin>>n>>m;
		for(int i = 0;i<n;i++)
            cin>>minSalary[i];
        for(int i = 0;i<m;i++)
        {
            cin>>offeredSalary[i]>>maxJobOffers[i];
        }
        for(int i = 0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j = 0;j<m;j++)
            {
                if(s[j] == '1')
                    qual[i][j]=1;
            }
        }
        ll totalSalary = 0;
        for(int i = 0;i<n;i++)
        {
            ll maxOffering = -1;
            ll z = -1;
            for(int j = 0;j<m;j++)
            {
                if(qual[i][j] == 1)
                {
                    if(maxJobOffers[j] > 0)
                    {
                        if(maxOffering < offeredSalary[j])
                            maxOffering = offeredSalary[j],z=j;
                    }
                }
            }
            if(maxOffering < minSalary[i])
                continue;
            totalSalary += maxOffering;
            maxJobOffers[z] -=1;
            gotJob[i] = true;
            gaveJob[z] = true;
        }
        ll candidatesPlaced = 0;
        ll compWithNoCan = 0;
        for(int i = 0;i<n;i++)
            if(gotJob[i])
                candidatesPlaced +=1;
        for(int i = 0;i<m;i++)
            if(!gaveJob[i])
                compWithNoCan +=1;
        cout<<candidatesPlaced<<" "<<totalSalary<<" "<<compWithNoCan<<endl;

    }
	return 0;

}
