#include <iostream>
#define MAX 1000001
using namespace std;
int x[MAX][4];
int val[MAX][4];
void initial(int n)
{
    for (int i =0;i<=n+1;i++)
    {

        for(int j =0;j<=3;j++)
        {
            val[i][j]=0;
            x[i][j]=0;
        }
    }
}
int reachable(int row,int col,int n)
{
    if(col >3 || col<1)
    {
        return 0;
    }
    if(row > n)
    {
        return n;
    }
    if(val[row][col]!=0)
    {
        return val[row][col];
    }
    if(x[row][col]==1)
    {
        val[row][col] = row-1;
        return row-1;
    }
    int temp = 0;
    temp = max(reachable(row+1,col-1,n),temp);
    temp = max(reachable(row+1,col+1,n),temp);
    temp = max(reachable(row+1,col,n),temp);
    val[row][col] = temp;
    return temp;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,q;
        cin>>n>>q;
        initial(n);
        for(int i =0;i<q;i++)
        {
            int a,b;
            cin>>a>>b;
            x[a][b]=1;
        }
        int reach = max(reachable(1,1,n),max(reachable(1,2,n),reachable(1,3,n)));
        cout<<reach<<endl;
    }
    return 0;
}
