#include <iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,m;
        cin>>n>>m;
        int i,j;
        int count = 0;
        int minr,minc;
        int a[n][m],b[n][m],c[n][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>b[i][j];
                c[i][j] = a[i][j] - b[i][j];
            }
        }


    }
    return 0;
}
