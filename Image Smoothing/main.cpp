#include <iostream>

using namespace std;
int n,m;
int f[50][50];
int g[150][150];
int ng[150][150];
int item(int i,int j,int fi,int fj)
{
    if(i>=n||j>=n||i<0||j<0)
        return 0;
    return g[i][j]*f[fi][fj];
}
int solve(int i , int j)
{
    int temp=0;
    int x=0;
    for(int k =i-m;k<=i+m;k++)
    {
        int y =0;
        for(int l =j-m;l<=j+m;l++)
        {
            temp+=item(k,l,x,y++);
            //cout<<temp<<" ";
        }
        x++;
        //cout<<endl;
    }
    return temp;
}
int main()
{
    cin>>n>>m;
    for(int i =0;i<2*m+1;i++)
    {
        for(int j =0;j<2*m+1;j++)
        {
            cin>>f[i][j];
        }
    }
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cin>>g[i][j];
        }
    }
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            ng[i][j]= solve(i,j);
        }
    }
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<ng[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
