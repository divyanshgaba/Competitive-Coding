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

double area(pi a,pi b, pi c)
{
    return abs((a.F*(b.S-c.S) + b.F*(c.S-a.S) + c.F*(a.S-b.S))/2.0);
}

int main()
{
	fast;
	int t;
	cin>>t;
    while(t--)
    {
        pi a,b,c,d;
        cin>>a.F>>a.S;
        cin>>b.F>>b.S;
        cin>>c.F>>c.S;
        cin>>d.F>>d.S;
        double A =area(a,b,c);
        double A1 =area(d,b,c);
        double A2 =area(a,d,c);
        double A3 =area(a,b,d);
        if(A == A1+A2+A3)
            cout<<"INSIDE\n";
        else
            cout<<"OUTSIDE\n";

    }
	return 0;

}
