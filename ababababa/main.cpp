#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

map<string,int> mp;
string s;
int len;

void ans(int st,int en)
{
    string k = s.substr(st,en-st+1);
    //cout<<k<<endl;
    if(mp.count(k)>0)
        mp[k]++;
    else
        mp[k] =1;
    if(st==en)
        return;
    ans(st+1,en);
    ans(st,en-1);
}

int main()
{
    fast;
    int test;
    cin>>test;
    while(test--)
    {
        cin>>s;
        len = s.length();
        mp.clear();
        ans(0,len-1);
        int flag =0;
        for(auto it : mp)
        {
            //cout<<"hi"<<endl;
            if(it.S == 2)
            {
                cout<<it.F;
                flag =1;
                break;
            }
        }
        if(flag ==0)
            cout<<"-1";
        cout<<endl;
    }
    return 0;
}
