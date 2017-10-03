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
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
vector<string> s;
char str[]= "123456";
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     s.PB(string(a));
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}
bool valid(string s)
{
    for(int i = 0;i<6;i++)
    {
        if(s[s[i]-'0'-1] !=((i+1)+'0'))
            return true;
    }
    return false;
}
vector<set<int>> v(7);

bool possible(string s)
{
    int a[7];
    vector<set<int>> k = v;
    for(int i = 1;i<=6;i++)
    {
        a[i] = s[i-1]-'0';
    }
    for(int i = 1;i<=6;i++)
    {
        if(k[i].find(a[i])==k[i].end())
            return false;
        k[i].clear();
        k[i].insert(a[i]);
    }
    return true;
}

int main()
{
	fast;
	vector<string> t;
    permute(str, 0, strlen(str)-1);
	int test=1;
	cin>>test;
    for(auto i:s)
    {
        if(valid(i))
            continue;
        t.PB(i);
    }
	while(test--)
    {
		int n;
		cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i = 1;i<=6;i++)
        {
            for(int j = 1;j<=6;j++)
            {
                if(i==j)
                    continue;
                v[i].insert(j);
            }
        }
        bool ans = true;
        for(int i = 0;i<n-1;i++)
        {
            if(a[i]==a[i+1])
            {
                ans = false;
                break;
            }
            v[a[i]].erase(a[i+1]);
            v[a[i+1]].erase(a[i]);
        }
        if(!ans)
        {
            cout<<"-1\n";
            continue;
        }
        ans = false;
        for(auto i:t)
        {
            if(possible(i))
            {
                for(auto j:i)
                    cout<<j<<" ";
                cout<<endl;
                ans = true;
                break;
            }
        }
        if(!ans)
            cout<<"-1\n";



    }
	return 0;

}
