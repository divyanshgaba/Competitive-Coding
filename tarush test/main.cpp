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


bool check(int m,int n)
{
    int x = m*n;
    int term = m + n/2;
    int psq = term*term;
    //cout<<m<<" "<<n/2<<" "<<m+n/2<<endl;
    //cout<<psq<<endl;
    int sq = psq-x;
    int ssq = sqrt(sq);
    //cout<<sq<<" "<<ssq<<endl;
    if(sq == ssq*ssq)
        return true;
    return false;
}
ofstream fout("checkfor");
void diviors(int n)
{
    fout<<n<<": ";
    for(int i =1;i<=n;i++)
        if(n%i ==0)
            fout<<"{"<<i<<", "<<n/i<<"} ";
    fout<<endl;
}

int main()
{
	fast;

	for(int i =2;i<10000;i++)
    {
        int x = i;
        bool got = false;
        diviors(i);
        for(int j = 1;j<=sqrt(x);j++)
        {
            if(x % j == 0)
            {
                bool check1 =check(j,x/j);
                bool check2 =check(x/j,j);
                if(x/j == j)
                    check2 = false;
                if(check1)
                {
                    cout<<x<<" "<<j<<" "<<x/j<<endl;
                    got = true;

                }
                if(check2)
                {
                    cout<<x<<" "<<x/j<<" "<<j<<endl;
                    got = true;

                }
            }
        }
        if(!got)
        {
            cout<<x<<" Not possible\n";
            //fout<<x<<" Not possible"<<endl;
        }
        else
        {
            //fout<<x<<" Possible"<<endl;
        }
    }
	return 0;

}
