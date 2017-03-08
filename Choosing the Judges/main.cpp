#include <iostream>
#include <cstring>
using namespace std;
long long score;
long long hold[10001];
long long calc(long long a[],int n,int i)
{
    if(i>=n)
        return 0;
    if(hold[i]!=0)
        return hold[i];
    //cout<<a[i]<<" ";
    long long temp= a[i]+ max(calc(a,n,i+2),calc(a,n,i+3));
    hold[i] =temp;
    return temp;
}
int main()
{
    int test;
    cin>>test;

    for(int j=1;j<=test;j++)
    {
        int n;
        cin>>n;
        long long a[n];
        score =0;
        memset(hold, 0, sizeof(hold[0]) * n);
        for(int i =0;i<n;i++)
        {
            cin>>a[i];
        }
        score = max(calc(a,n,0),calc(a,n,1));
        //cout<<endl;
        cout<<"Case "<<j<<": "<<score<<endl;
    }
    return 0;
}
