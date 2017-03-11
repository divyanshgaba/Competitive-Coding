#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long pantry[15];
long long cost[15];
long long bought[15];
long long rec[30][30];
long long r,p,n,m;

bool possible()
{
    long long count=0;
    for(int i =0;i<r;i++)
    {
        int flag =1;
        for(int j =0;j<p;j++)
        {
            if(rec[i][j]==1&&bought[j]!=1)
            {
                flag=0;
                break;
            }
        }
        if(flag ==1)
        {
            count++;
            if(count==n)
                return true;
        }
    }
    return false;
}
void print()
{
    for(int i =0;i<p;i++)
        cout<<i<<" ";
    cout<<endl;
    for(int i =0;i<p;i++)
        cout<<bought[i]<<" ";
    cout<<endl;
}

long long answer(long long money,long long i)
{
    if(i==p)
    {
       //print();  cout<<money<<" "<<i<<endl;
       if(possible())
            return money;
       return 1000000000 ;
    }
    if(possible())
    {
        return money;
    }
    long long temp =2147003040;
    if(bought[i]==0)
    {
        bought[i]=1;
        temp = min(temp,answer(money+cost[i],i+1));
        bought[i]=0;
    }
    temp=min(temp,answer(money,i+1));

    return temp;
}

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        memset(bought,0,sizeof(bought[0])*15);
        cin>>r>>p>>n>>m;
        for(int i =0;i<m;i++)
            cin>>pantry[i];
        for(int i =0;i<p;i++)
            cin>>cost[i];
        for(int i =0;i<m;i++)
        {
            bought[pantry[i]]=1;
        }
        for(int i =0;i<r;i++)
        {
            for(int j =0;j<p;j++)
            {
                cin>>rec[i][j];
            }
        }
        cout<<answer(0,0)<<endl;
    }
    return 0;
}
