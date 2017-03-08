#include <iostream>
#include <stdlib.h>


using namespace std;
#define mod 10000000
int memo[10002][12]={0},a[1001],n,t[10005]={0};
int f(int i,int h)
{
    int yolo;
    if(memo[i][h])
        return memo[n][h];
    if(abs(h)>(10*n))
    {
        return 0;
    }
    if(!i&&h)
        return 0;
    if(!i&&!h)
        return 1;
    yolo=f(i-1,h-a[i])%mod+f(i-1,h+a[i])%mod;
    memo[i][h]=yolo;
    cout<<yolo;
    return yolo;

}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {

        cin>>n;
        int i,monie=0;
        for(i=0;i<n;i++)
            {
              cin>>a[i];
              t[i]=a[i];
            }
            for(i=n-1;i>=0;i--)
            {
                for(int j=i-1;j>=0;j--)
                {
                    t[n-i-1]+=t[j]%mod;
                }
                cout<<t[i];
            }
            for(i=0;i<n;i++)
            monie+=abs(f(i,t[i]));
            cout<<monie<<endl;


    }
    return 0;
}
