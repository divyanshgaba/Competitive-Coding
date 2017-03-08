#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n,m;
        float p,k;
        cin>>n>>m>>p>>k;
        float f1 = (n*m-1)%2==0?0:1;
        float f2;
        if(n*m %2 ==0)
            f2 = (((n*m)/2) - 1)%2==0?0:1;
        else
            f2 = (n*m)%2==0?0:1;
        float prob1 = (f1+f2)*0.5,prob2=0;
       // cout<<prob1<<endl;
        for(int i = 1;i<=p&&prob1!=1;i++)
        {
            prob2 += prob1*i/k;
        }
        if(prob1==1)
            prob2=prob1;
        printf("%f\n",prob2);

    }
    return 0;
}
