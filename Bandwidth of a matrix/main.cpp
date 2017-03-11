#include <iostream>

using namespace std;
int a[501][501];
int n;



int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        int one=0;
        for(int  i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                cin>>a[i][j];
                if(a[i][j]==1)
                    one++;
            }
        }
        int bw=0;
        int act=n;
        while(one>act)
        {
            n--;
            act += 2*n;
            bw++;
        }
        cout<<bw<<endl;

    }
    return 0;
}
