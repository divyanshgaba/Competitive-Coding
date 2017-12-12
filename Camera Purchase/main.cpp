#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int camera[n],cost[n];
    for(int i = 0;i<n;i++)cin>>camera[i];
    for(int i = 0;i<n;i++)cin>>cost[i];
    vector<int> v[32];
    for(int j = 0;j<32;j++)
    {
        int a = 1&j!=0;
        int b = ((1<<1)&j)!=0;
        int c = ((1<<2)&j)!=0;
        int d = ((1<<3)&j)!=0;
        int e = ((1<<4)&j)!=0;
        for(int i = 0;i<n;i++)
        {
            if(camera[i]==1&&a==1)
                v[a + 2*b + 4*c + 8*d + 16*e].push_back(cost[i]);
            else if(camera[i]==2&&b==1)
                v[a + 2*b + 4*c + 8*d + 16*e].push_back(cost[i]);
            else if(camera[i]==3&&c==1)
                v[a + 2*b + 4*c + 8*d + 16*e].push_back(cost[i]);
            else if(camera[i]==4&&d==1)
                v[a + 2*b + 4*c + 8*d + 16*e].push_back(cost[i]);
            else if(camera[i]==5&&e==1)
                v[a + 2*b + 4*c + 8*d + 16*e].push_back(cost[i]);
        }

    }
    for(int i = 0;i<32;i++)
        sort(v[i].begin(),v[i].end());
    int q;
    cin>>q;
    for(int _=0;_<q;_++)
    {
        int d;
        cin>>d;
        int t;
        int a[6]={0};
        for(int __ = 0;__<d;__++)
        {
            cin>>t;
            a[t]=1;
        }
        int k;
        cin>>k;
        if(v[(a[1] + 2*a[2] + 4*a[3] + 8*a[4] + 16*a[5])].size() <= k)
            printf("-1\n");
        else
            printf("%d\n",v[(a[1] + 2*a[2] + 4*a[3] + 8*a[4] + 16*a[5])][k-1]);
    }
	return 0;

}
