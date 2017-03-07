#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;
int memo[300][10][300];
int mcou=0;
int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
int convert(string s,int a,int b)
{
    string::iterator it = s.begin() + a;
    char temp[b-a+1];
    int j =0;
    for(int i = a;i<b;i++)
    {
        temp[j++]=*it;
        it++;
    }
    return stoi(temp);
}
void initialize(string s,int n,int m)
{
    int count = min(n,m);
    mcou=0;
    for(int i = 0;i<count;i++)
    {
        memo[i][0][mcou++] = convert(s,0,i);
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
        int ans =1;
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<y;j++)
            {
                int temp = min(n,i+m);
                for(int k =i+1;k<temp;k++)
                {
                    int val = convert(s,i+1,k);
                    int h=0;
                    for(int l = 0;i<mcou;i++)
                    {
                        memo[k][j+1][h]=gcd(val,memo[k][j][h++]);
                    }
                }

            }

            for(int j =x+1;j<y+1;j++)
            {
                for(int l =0;l<mcou;l++)
                {
                    ans = max(ans,memo[i][j][l]);
                }
            }
        }
        cout<<ans<<endl;



    }
    return 0;
}
