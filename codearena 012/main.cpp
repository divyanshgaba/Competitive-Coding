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
int mr[101][101];
int mb[101][101];
bool right(int i , int j)
{

    if(j==n)
        return true;
    if(i==n||i<0)
        return false;
    if(a[i][j] != 2)
        return false;
    if(mr[i][j]!=0)
    {
        if(mr[i][j]==1)
            return true;
        return false;
    }
    bool temp= right(i+1,j+1) + right(i,j+1) + right(i-1,j+1);
    if(temp)
        mr[i][j] = 1;
    else
        mr[i][j]=-1;
    return temp;
}
bool bot(int i , int j)
{

    if(i==n)
        return true;
    if(j==n||j<0)
        return false;
    if(a[i][j] != 1)
        return false;
    if(mb[i][j]!=0)
    {
        if(mb[i][j]==1)
            return true;
        return false;
    }
    bool temp = bot(i+1,j+1) + bot(i+1,j-1) + bot(i+1,j);
    if(temp)
        mb[i][j]=1;
    else
        mb[i][j]=-1;
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
    bool one=false,two=false;
    for(int i =0;i<n;i++)
    {
        one = bot(0,i);
        if(one)
            break;
    }
	for(int i =0;i<n;i++)
    {
        two = right(i,0);
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
