#include <iostream>
#include <algorithm>
#define MAX 1e17
using namespace std;
long long n,k;
long long ans[5001][5001];
long long rec;
long long dip[5001][5001];
pair<int,int> a[5001];
long long cost(int i, int j)
{

    if(dip[i][j]!=0)
        return dip[i][j];
    if(i==j)
    {
        return 0;
    }
    long long temp=((a[j].first - a[i].first)*a[j].second) + cost(i,j-1);
    dip[i][j]=temp;
    return temp;
}
long long answer(int i,int j)
{
    if(ans[i][j]!=0)
        return ans[i][j];
    if(j==1)
    {
        return cost(i,n-1);
    }
    long long temp = MAX;
    for(int k = i;k<=(n-j);k++)
    {
        temp = min(temp,cost(i,k)+answer(k+1,j-1));
    }
    ans[i][j]=temp;
    return temp;
}
int main()
{
    cin>>n>>k;
    k=k%2500;
    for(int i =0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    cout<<answer(0,k)<<endl;
    return 0;
}
