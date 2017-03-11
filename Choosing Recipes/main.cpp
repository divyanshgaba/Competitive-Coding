#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int r,p,n,m;
        cin>>r>>p>>n>>m;
        int got[m];
        for(int i =0;i<m;i++)
            cin>>got[i];
        int cost[p];
        for(int i =0;i<p;i++)
            cin>>cost[i];
        int paisa[r][p];
        for(int i =0;i<m;i++)
            cost[got[i]]=0;
        for(int j =0;j<r;j++)
        {
            for(int i =0;i<p;i++)
            {
                cin>>p[j][i];
            }
        }

        int sum=0;
        for(int i =0;i<n;i++)
        {
            sum+=paisa[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
