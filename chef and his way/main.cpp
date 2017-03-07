#include <iostream>
#include <cmath>
using namespace std;
int n;
int k;
int a[100001];
int jump[100001];
int solve(int src)
{
    if(abs(src-a[n-1]) <=k)
        return a[n-1];
    int total=1;
    int i;
    for(i =0;i<n;i++)
    {
        if(done[i]==0)
            break;
    }
    if(i>n)
        return 1;
    else
    {
        for(int j =0;j<k;j++)
        {
            done[i]=1;

        }
    }
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<solve();

}
