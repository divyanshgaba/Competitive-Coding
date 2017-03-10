#include <iostream>
#include <algorithm>
using namespace std;
int a[301][301];
int b[301][301];
pair<int,int> mem[9001];
int give_n()
{
    int n;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {

        }
    }
}
int main()
{
    int n;
    cin>>n;
    int k =1;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cin>>a[i][j];
            mem[a[i][j]] = make_pair(i,j);
            b[i][j]=a[i][j];
        }
    }
    for(int i =0;i<n;i++)
    {
        sort(b[i],b[i]+n);

    }
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
