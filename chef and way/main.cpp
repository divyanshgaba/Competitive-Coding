#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)


using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const ll INF = 1e13;
int n,k;
int a[100002];
double ans[100002];
double lg[100002];
double answer(int i)
{
    if(i==n)
        return lg[i];
    double temp = answer(i+1);
    for(int j =2;j<=k;j++)
    {
        temp = min(temp,answer(i+j));
    }
    temp+=lg[i];
    return temp;
}

int main()
{
    cin>>n>>k;
    for(int i =1;i<=n;i++)
        cin>>a[i],lg[i] = log10(a[i]);
    cout<<answer(1)<<endl;
    return 0;
}
