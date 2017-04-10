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

int n;
int a[101][101];
int mem[101][101][3];
bool ans(int i, int j,int check)
{
    if(i==n)
    {
        return true;
    }
    if(j<0 ||j>=n)
        return false;
    if(a[i][j] == 0)
        return false;
    if(a[i][j] != check)
        return false;
    if(mem[i][j][check]!=0)
    {
        if(mem[i][j][check] == -1)
            return false;
        return true;
    }
    bool temp = max(ans(i+1,j,check),ans(i+1,j-1,check));
    temp = max(temp,ans(i+1,j+1,check));
    temp = max(temp,ans(i,j-1,check));
    temp = max(temp,ans(i,j,check));
    temp = max(temp,ans(i,j+1,check));
    if(temp)
        mem[i][j][check] = 1;
    else
        mem[i][j][check]= -1;
    return temp;
}
bool sol(int i, int j,int check)
{
    if(j==n)
    {
        return true;
    }
    if(i<0 ||i>=n)
        return false;
    if(a[i][j] == 0)
        return false;
    if(a[i][j] != check)
        return false;
    if(mem[i][j][check]!=0)
    {
        if(mem[i][j][check] == -1)
            return false;
        return true;
    }
    bool temp = max(ans(i+1,j+1,check),ans(i,j+1,check));
    temp = max(temp,ans(i-1,j+1,check));
    temp = max(temp,ans(i-1,j,check));
    temp = max(temp,ans(i,j,check));
    temp = max(temp,ans(i+1,j,check));
    if(temp)
        mem[i][j][check] = 1;
    else
        mem[i][j][check]= -1;
    return temp;
}
int main()
{
	fast;
	cin>>n;
	for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
            cin>>a[i][j];
    }
    bool one,two;
    for(int i =0;i<n;i++)
    {
        if(a[0][i]==0)
            continue;
        one = ans(0,i,1);
        if(one)
            break;
    }
	for(int i =0;i<n;i++)
    {
        if(a[i][0]==0)
            continue;
        two = sol(i,0,2);
        if(two)
            break;
    }
    if(one&&two)
        cout<<"AMBIGUOUS\n";
    else if(one)
        cout<<"1\n";
    else if(two)
        cout<<"2\n";
    else
        cout<<"0\n";
	return 0;

}
