#include <iostream>

using namespace std;
int con[3001][3001];


int main()
{
    int n;
    cin>>n;
    for(int i =0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        con[x][y]=1;
        con[y][x]=1;
    }
    return 0;
}
