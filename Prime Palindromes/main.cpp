/*
ID: divyans19
PROG: pprime
LANG: C++11
*/
#include<bits/stdc++.h>
//#define fast ios_base::sync_with_stdio(0); fin.tie(0); fout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
char c[11];
char d[] = "0123456789";
int n;
int a,b;
vector<int> ans;
void prime()
{
    //fout<<c<<endl;
    int temp = stoi(c);
    if (!(temp<=b && temp>=a))
        return;
    for(int i =2;i<=sqrt(temp);i++)
    {
        if(temp%i == 0)
            return;
    }
    ans.PB(temp);
}

void palindrome(int st,int en)
{
    if(st>en)
    {
        prime();
        return;
    }
    for(int i =0;i<10;i++)
    {
        if(st==0&&i==0)            continue;
        c[st] = c[en] = d[i];
        palindrome(st+1,en-1);
    }
}
int main()
{
	//fast;
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	fin>>a>>b;
	n = floor(log10(b))+1;
	for(int i =1;i<=n;i++)
    {
        c[i]='\n';
        palindrome(0,i-1);
    }
    for(auto it:ans)
        fout<<it<<"\n";
	return 0;

}
