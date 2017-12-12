/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
#include <bits/stdc++.h>
#define F(i,p,n) for(LL i=p; i<n; i++)
#define loop(i, n) for(LL i=0; i<n; i++)
#define fast   ios_base::sync_with_stdio(0); cin.tie(0)
#define dd double
#define mem(a, v) memset(a, v, sizeof(a))
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;
int dist(vector<int> a,vector<int> b)
{
    int cnt = 0;
    for(int i = 0,n=a.size();i<n;i++)
        if(a[i]!=b[i])
            cnt++;
    return cnt;
}
int main()
{
	fast;
	int test=1;
	cin>>test;
	while(test--)
    {
		int n;
		cin>>n;
		vector<int> a(n),b,c;
		for(int i = 0;i<n;i++) cin>>a[i];
		b=a;
		sort(b.begin(),b.end());
		for(int i = 2;i<b.size();i++) c.push_back(b[i]);
		if(n>=3)
        {
            c.push_back(b[0]);
            c.push_back(b[1]);
        }
        else
        {
            if(n>=2) c.push_back(b[1]);
            c.push_back(b[0]);
        }
		unordered_map<int,list<int>> m;
		for(int i = 0;i<n;i++) m[b[i]].push_back(c[i]);
		for(int i = 0;i<n;i++)
        {
            b[i]=m[a[i]].front();
            m[a[i]].pop_front();
        }
        cout<<dist(a,b)<<endl;
        copy(b.begin(),b.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
    }
	return 0;

}
