/*
ID: divyans19
PROG: holstein
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

int req[26];
int feed[26][26];
int temp[26];
string s = "0000000000000000";
int cnt =16;
int g,v;
string k = "1111111111111111";
int count(string s)
{
    int cn=0;
    for(int i =0;s[i]!='\0';i++)
    {
        if(s[i]=='1')
            cn++;
    }
    return cn;
}
bool equala()
{
    for(int i =0;i<v;i++)
    {
        if(req[i]>temp[i])
            return false;
    }
    return true;
}
void solve(int i)
{
    if(i==g)
    {
        int len = count(s);
        if(len <= cnt && equala())
        {
            if(len == cnt)
            {
                if(s<k)
                    k=s;
            }
            else
                k=s;
            cnt = len;
        }
        return;
    }
    s[i] ='1';
    for(int j =0;j<v;j++)
    {
        temp[j]+=feed[i][j];
    }
    solve(i+1);
    for(int j =0;j<v;j++)
    {
        temp[j]-=feed[i][j];
    }
    s[i]='0';
    solve(i+1);

}
int main()
{
    ifstream fin("holstein.in");    ofstream fout("holstein.out");
	//fast;
	fin>>v;
	for(int i =0;i<v;i++)
        fin>>req[i];
    fin>>g;
    for(int i =0;i<g;i++)
        for(int j=0;j<v;j++)
            fin>>feed[i][j];
    solve(0);
    fout<<cnt;
    for(int i =0;i<g;i++)
        if(k[i]=='1')
            fout<<" "<<i+1;
    fout<<endl;
	return 0;

}
