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

void print(vector<int> a)
{
    for(auto i:a)
        cout<<i<<" ";
    cout<<endl;
}
map<pair<int,vector<int>>, int > mp;
void answer(int i,vector<int> a)
{
    if(i == a.size() - 1)
        return;
    if(mp.count(MP(i,a)) > 0)
        return;
    mp[MP(i,a)] = 1;
    if(a[i] > 0 && a[i+1] > 0)
    {
        a[i]-=1,a[i+1]-=1;
        a[i+2]+=1;
        answer(i,a);
        a[i+2]-=1;
        a[i]+=1,a[i+1]+=1;
    }
    answer(i+1,a);
}

int main()
{

	int test=1;
	cin>>test;
	while(test--)
    {
        mp.clear();
        cin>>n;
        vector<int> a(100,0);
        int x;
        for(int i = 0;i<n;i++)
            cin>>a[i];
        answer(0,a);
        set<vector<int>> k;
        k.insert(a);
        for(auto i:mp)
            k.insert(i.F.S);
        cout<<k.size()<<endl;
    }
	return 0;

}
