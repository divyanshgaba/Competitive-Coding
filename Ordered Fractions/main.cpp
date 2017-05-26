/*
ID: divyans19
PROG: frac1
LANG: C++11
*/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); fin.tie(0); fout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

bool grid[163][163];

ifstream fin("frac1.in");ofstream fout("frac1.out");
int main()
{
	//fast;
	int n;
	fin>>n;
	vector<pi>  fr;
	fr.PB(MP(0,1));
	fr.PB(MP(1,1));
	for(int i =1;i<n;i++)
    {
        for(int j =i+1;j<=n;j++)
        {
            fr.PB(MP(i,j));
        }
    }
    sort(fr.begin(),fr.end());
    vector<pair<double,pi> > ans;
    for(auto it :fr)
    {
        if(!grid[it.F][it.S])
        {

            grid[it.F][it.S]=true;
            ans.PB(MP(double(double(it.F)/double(it.S)),it));
            for(int k =2;k<=n;k++)
            {
                if(it.F*k <= n && it.S*k <= n)
                    grid[it.F*k][it.S*k] = true;
                else
                    break;
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(auto it:ans)
    {
        fout<<it.S.F<<"/"<<it.S.S<<endl;

    }
	return 0;

}
