/*
ID: divyans19
PROG: sprime
LANG: C++11
*/
#include<bits/stdc++.h>
//#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

char c[10];
char f[] ="2357";
char l[] ="1379";
char d[] ="1379";
int n;
vi ans;
bool prime(int a)
{
    if(a==2)
        return true;
    for(int i =2;i<=sqrt(a);i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}

void sprime()
{
    int temp = stoi(c);
    int hold = temp;
    while(temp != 0)
    {
        if(!prime(temp))
        {
            return;
        }
        temp /=10;
    }
    ans.PB(hold);

}
void gen(int i)
{
    if(i==n)
    {
        sprime();
        //cout<<c<<endl;
        return;
    }
    if(i==0)
    {
        for(int j =0;j<4;j++)
        {
            c[i] = f[j];
            gen(i+1);
        }
        return;
    }
    else if (i==n-1)
    {
        for(int j =0;j<4;j++)
        {
            c[i] = l[j];
            gen(i+1);
        }
        return;
    }
    for(int j =0;j<4;j++)
    {
        c[i] = d[j];
        gen(i+1);
    }

}
int main()
{
	//fast;
	//ifstream cin("sprime.in");	ofstream cout("sprime.out");
	cin>>n;
	c[n]='\0';
	gen(0);
	for(auto it:ans)
        cout<<it<<"\n";
	return 0;

}
