/*
ID: divyans19
PROG: hamming
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
int check;
int n,b,d;

int flip(int n)
{
    int cnt=0;
    while(n)
    {
        if(n&1)
            cnt++;
        n>>=1;
    }
    return cnt;
}

bool vis[257];

int main()
{
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");
	//fast;
	fin>>n>>b>>d;
	check = round(pow(2,b));
	vi a;
	a.PB(0);
	while(a.size()<n)
    {
        for(int i =1;i<check;i++)
        {
            if(!vis[i])
            {
                int j =0;
                for(j =0;j<a.size();j++)
                    if(flip(a[j]^i) < d)
                        break;
                if(j>=a.size())
                    a.PB(i);

            }
        }
    }
    sort(a.begin(),a.end());
    for(int i =0;i<n;i++)
    {
        if(!((i+1)%10))
            fout<<a[i]<<endl;
        else if(i<n-1)
            fout<<a[i]<<" ";
        else
            fout<<a[i]<<endl;
    }


	return 0;

}
