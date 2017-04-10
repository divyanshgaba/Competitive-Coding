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

int countNumbersWith3(int n)
{
   if (n < 3)
      return 0;
   int d = log10(n);
   int *a = new int[d+1];
   a[0] = 0, a[1] = 1;
   for (int i=2; i<=d; i++)
      a[i] = a[i-1]*9 + ceil(pow(10,i-1));
   int p = ceil(pow(10, d));
   int msd = n/p;
   if (msd == 3)
      return (msd)*a[d] + (n%p) + 1;
   if (msd > 3)
      return (msd-1)*a[d] + p + countNumbersWith3(n%p);
   return (msd)*a[d] + countNumbersWith3(n%p);
}


int main()
{
	fast;
	int test;
	cin>>test;
	while(test--)
    {
        int n;
        cin>>n;
        cout<<n-countNumbersWith3(n)<<endl;

    }
	return 0;

}
