#include <iostream>
using namespace std;

int a[1001][1001];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i =0;i<k;i++)
    {
        int r,c,s,d;
        cin>>r>>c>>s>>d;
        r--;c--;
        for(int j =r;j<r+s;j++)
        {
            for(int e =c;e<c+s;e++)
            {
                a[j][e]+=d;
            }
        }
    }
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
