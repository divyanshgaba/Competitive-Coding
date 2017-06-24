/************************************
 *	AUTHOR: 		Divyansh Gaba	*
 *	INSTITUTION: 	ASET, BIJWASAN	*
 ************************************/
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
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
	srand(time(NULL));
	ofstream fout("input.txt");
	int n = rand()%100 + 1;
	while(n < 80)
        n = rand()%100 + 1;
	fout<<n<<endl;
	cout<<n<<endl;
	for(int i = 0;i<n;i++)
    {
        int a = rand()%1000000 + 2;
        fout<<a<<" ";
        cout<<a<<" ";
    }
    fout<<endl;
    int q = rand()%100 + 1;
    while( q< 80)
        q = rand()%100 + 1;
    fout<<q<<endl;
    cout<<q<<endl;
    for(int i  = 0;i<q;i++)
    {
        int l = rand()%n + 1;
        int r = rand()%n + 1;
        while(r<l)
            r = rand()%n + 1;
        int x = rand()%1000000 + 1;
        int y = rand()%1000000 + 1;
        while(y<x)
             y = rand()%1000000 + 1;
        fout<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
        cout<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
    }

	return 0;

}
