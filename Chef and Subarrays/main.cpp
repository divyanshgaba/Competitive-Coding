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

int n;
int a[50];

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		cin>>n;
		for(int i = 0;i<n;i++)
            cin>>a[i];
        int product[n],sum[n];
        product[0]=sum[0]=a[0];
        for(int i = 1;i<n;i++)
            product[i]=product[i-1]*a[i],sum[i]=sum[i-1]+a[i];
        int cnt = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = i;j<n;j++)
            {
                int a = product[j];
                int b = sum[j];
                if(i)
                    a/=product[i-1],b-=sum[i-1];
                if(a==b)
                    cnt++;

            }
        }
        cout<<cnt<<endl;
    }
	return 0;

}
