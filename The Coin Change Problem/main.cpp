#include <iostream>
#include <algorithm>
using namespace std;
long long n,m;
long long a[51];
long long mem[300][100];
long long answer(long long v,long long c)
{
    if(v==n)
        return 1;
    if(v>n)
        return 0;
    if(mem[v][c]!=0)
        return mem[v][c];
    long long temp=0;
    for(long long i =c;i<m&&v+a[i]<=n;i++)
    {
        temp+=(answer(a[i]+v,i));
    }
    mem[v][c]=temp;
    return temp;


}
int main()
{
    cin>>n>>m;
    for(int i =0;i<m;i++)
    {
        cin>>a[i];
    }
    sort(a,a+m);
    cout<<answer(0,0)<<endl;
    return 0;
}
