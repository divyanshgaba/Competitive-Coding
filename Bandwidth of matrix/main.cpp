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
        int zero =0;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                cin>>a[i][j];
                if(a[i][j]==0)
                    zero++;
            }
        }
        int bw = n-1;
        for(int i =1;i<n;i++)
        {
            if(zero >= 2*(n-i))
            {
                bw--;
                zero -= 2*(n-i);
            }
            else
                break;

        }
        cout<<bw<<endl;

    }
    return 0;
}
