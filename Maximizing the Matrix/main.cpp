#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
array<array<int,102>,102> a,b,c,d,e;
vector<pair<int,int> > hol,real;
long long mult=0;
int n,k;
long long multiply()
{
    long long sum=0;
    int i,j,m;
    for(i = 1; i <=n; i++)
    {
    for(j = 1; j <= n; j++)
    {
        bool value = false;
        for(m = 1; m <= n; m++)
        {
            value =(value||(a[i][m] && b[m][j]));
            if(value)
                break; // early out
        }
        c[i][j] = value==true?1:0;
        sum+=c[i][j];

    }
    }
    /*
    long long sum=0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = 0;
            for (int k = 1; k <= n; k++)
            {
                c[i][j] += a[i][k]*b[k][j];
            }
            sum+=c[i][j];
        }
    }*/
    if(mult<sum)
    {
        mult = sum;
        d=a;
        e=b;
        hol=real;
    }
    //cout<<"hi"<<endl;
    //cout<<sum<<endl;
    return sum;
}

long long answer(int i,int j,int k)
{
    if(i==n+1&&j==n+1)
    {
        return multiply();
    }
    if(i==n+1)
    {
        //cout<<"yo\n";
        answer(1,j+1,k);
        return 0;
    }
    long long temp = answer(i+1,j,k);
    if(k>0)
    {
        swap(a[i][j],b[i][j]);
        real.push_back(make_pair(i,j));
        temp=max(temp,answer(i+1,j,k-1));
        real.pop_back();
        swap(a[i][j],b[i][j]);
    }
    return temp;
}
int main()
{
    cin>>n>>k;
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
        {
            cin>>b[i][j];
        }
    }
    answer(1,1,k);
    int count=0;

    /*for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
        {
            if(d[i][j]!=a[i][j])
            {
                count++;
                hol.push_back(make_pair(i,j));
            }
        }
    }*/
    cout<<hol.size()<<endl;
    for(vector<pair<int,int> >::iterator it = hol.begin();it != hol.end();it++)
        cout<<(*it).first<<" "<<(*it).second<<endl;

    return 0;
}
