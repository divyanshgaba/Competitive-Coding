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

int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		vector<unsigned int>a;
        unsigned int x = 42953;
        for(int i = 0;i<99988;i++)
        {
            a.push_back(x);
        }
        for(int i = 0;i<n-99991;i++)
        {
            a[i]-=1;
        }
        a.push_back(x+48412);
        a.push_back(x+48411);
        for(int i = 99990;i<n;i++)
            a.push_back(1);
        for(auto i:a)            cout<<i<<" ";
        //cout<<a.size();
        cout<<endl;
    }
	return 0;

}
