#include <iostream>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int a[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<=i;k++)
                {
                    for(int l=0;l<=j;l++)
                    {
                        if(a[i][j]<a[k][l])
                            count++;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}

