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
	int v[5];
	for(int i = 1;i<=4;i++) cin>>v[i];
	if(v[3]*2 < v[4] || v[4]*2 < v[3])
    {
        cout<<-1<<endl;
        return 0;
    }
    bool t = true;
    int c = max(v[3],v[4]);
    stack<int> st;
    st.push(c);
    c= max(c+1,2*v[4]+1);
    c = max(c,v[2]);
    if(c> 2*v[2])
        t= false;
    st.push(c);
    c++;
    c = max(c,v[1]);
    if(c>2*v[1])
        t = false;
    st.push(c);
    if(!t)
    {
        cout<<-1<<endl;
        return 0 ;
    }
    while(!st.empty())
        cout<<st.top()<<endl,st.pop();


	return 0;

}
