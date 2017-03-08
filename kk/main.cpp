#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
using namespace std;
long  memo[300][10][300];
int mcou=0;
long gcd(long a,long b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
long long convert(string s,int a,int b)
{
    string::iterator it = s.begin()+a;
    char temp[1000];
    int j =0;
    for(int i = a;i<b;i++)
    {

        temp[j++]=*it;
        it++;

    }
    cout<<":::"<<temp<<endl;
    return atoi(temp);
}
void initialize(string s,int n,int m)
{
    int count = min(n,m);
    mcou=0;
    for(int i = 0;i<count;i++)
    {
        memo[i][0][mcou++] = convert(s,0,i+1);
    }
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int m,x,y;
        cin>>m>>x>>y;
        initialize(s,n,m);
        long ans =1;
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<y;j++)
            {
                int temp = min(n,i+m);
                for(int k =i+1;k<temp;k++)
                {
                    long val = convert(s,i,k+1);
                    cout<<":: "<<val<<endl;
                    int h=0;
                    for(int l = 0;i<mcou;i++)
                    {
                        memo[k][j+1][l]=gcd(val,memo[k][j][l]);
                    }
                }

            }
            ans = 1;
            for(int j =x+1;j<=y+1;j++)
            {
                for(int l =0;l<mcou;l++)
                {
                    ans = max(ans,memo[i][j][l]);
                    //cout<<": "<<memo[i][j][l]<<endl;
                }
            }
        }
        cout<<ans<<endl;



    }
    return 0;
}
