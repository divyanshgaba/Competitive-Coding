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
    int n;
    cin>>n;
    vector<int> a;
    for(int i =0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    a.erase( unique( a.begin(), a.end() ), a.end() );
    for(auto it:a)
        cout<<it<<" ";
    cout<<endl;
    int m;
    cin>>m;
    int rank =a.size();
    for(int i =0;i<m;i++)
    {
        int x;
        cin>>x;
        while(rank!=0 && x>=a[rank-1])
        {
            rank--;
        }
        cout<<rank+1<<endl;

    }
    return 0;
}
