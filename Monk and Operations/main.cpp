#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
long long row[1001][2];
long long col[1001][2];
long long a[1001][1001];
int main()
{
    int n,m;
    cin>>n>>m;
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin>>a[i][j];
        }

    }
    long long v1,v2,v3,v4;
    cin>>v1>>v2>>v3>>v4;
    long long r=0,c=0;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            col[j][0]+=(abs(a[i][j]));
            row[i][0]+=(abs(a[i][j]));
            col[j][1]+=(abs(a[i][j]+v3));
            row[i][1]+=(abs(a[i][j]+v1));
        }
        r+=max(m*abs(v2),max(row[i][0],row[i][1]));

    }
    //cout<<r<<endl;
    for(int i =0;i<m;i++)
    {
        c+=max(n*abs(v4),max(col[i][0],col[i][1]));
        //cout<<col[i][1]<<" ";
    }
    //cout<<endl;
    //cout<<c<<endl;
    cout<<max(r,c)<<endl;
    return 0;
}
