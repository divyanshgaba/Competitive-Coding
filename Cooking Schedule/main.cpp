#include <iostream>
#include <cstring>
using namespace std;
int n,k;
string s;
int solve(int i,int k)
{

    int temp=1;
    char c=s[0];
    int hold=1;
    for(int j =1;j<n;j++)
    {
        if(s[j]==c)
        {
            temp++;
        }
        else
        {
            if(hold<temp)
                hold=temp;
            c=s[j];
            temp=1;
        }
    }
    if(hold<temp)
        hold=temp;
    //cout<<s<<" "<<hold<<endl;
    if(k!=0&&i!=n)
    {
        s[i] = s[i]=='0'?'1':'0';
        hold = min(hold,solve(i+1,k-1));
        s[i] = s[i]=='0'?'1':'0';
        hold = min(hold,solve(i+1,k));

    }
    return hold;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n>>k;
        string s;
        cin>>s;
        cout<<solve(0,k)<<endl;
    }
    return 0;
}
