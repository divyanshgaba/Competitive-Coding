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


int main()
{
	fast;
	int n,h;
	cin>>n>>h;
	double area = (double(h)/2);
	double req = area/(double(n));
	for(double i =1;i<n;i++)
    {
        double req = (i*h*h)/n;
        cout<<fixed<<setprecision(10)<<sqrt(req)<<" ";
    }

	return 0;

}
