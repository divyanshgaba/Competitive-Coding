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

const int N = 1e6;
int factor[N+1];

void prime()
{
    for(int i =2;i<=N;i+=2)
        factor[i]=2;
    for(int i = 3;i<=N;i+=2)
    {
        if(factor[i]==i)
        {
            for(int j = i+i;j<=N;j+=i)
                factor[j]=i;
        }
    }
}
int arr[N+1];
int digit_sum(int i )
{
    int ans = 0;
    while(i)
    {
        ans+=i%10;
        i/=10;
    }
    return ans;
}
int sum(int i)
{
    int ans = 0;
    while(i>1)
    {
        ans+=digit_sum(factor[i]);
        int h = factor[i];
        while(i%h==0)
            i/=h;
    }
    return ans;
}
void init()
{
    for(int i = 1;i<=N;i++)
    {
        factor[i]=i;
    }
    prime();
    for(int i = 1;i<=N;i++)
    {
        arr[i] =  arr[i-1]+sum(i);
    }

}


int main()
{
	fast;
	init();
	int test=1;
	cin>>test;
	while(test--)
    {
        int l,r;
        cin>>l>>r;
        cout<<arr[r]-arr[l-1]<<endl;

    }
	return 0;

}
