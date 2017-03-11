#include <iostream>
#define NUM(a) a -'0'
using namespace std;
string d;
string n;
int len;
int pop(string x)
{
    string h =d;
    int c=0;
    int count =0;
    for(int i =0;i<len;i++)
    {
        if(x[i]==h[i]&&x[i]=='1'&&c==1)
        {
            c=1;
            h[i]='1';

        }
        else if(x[i]==h[i]&&x[i]=='1'&&c==0)
        {
            c=1;
            h[i]='0';

        }
        else if((x[i]==1 || h[i]==1)&&c==1)
        {
            c=1;
            h[i]='0';
        }
        else if((x[i]==1 || h[i]==1)&&c==0)
        {
            c=0;
            h[i]='1';
        }
        h[i] = h[i]==x[i]?'0':'1';
        if(h[i]==1)
            count++;
    }


}
int ans(string n,int o)
{
    32
}
int main()
{

    cin>>s;
    d= s;
    len = s.length();
    for(int i =0;i<n;i++)
        d[i]='0';
    cout<<ans(n,0);
    return 0;
}
