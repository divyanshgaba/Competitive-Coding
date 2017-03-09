#include <iostream>
#include <cstring>
using namespace std;
int n;
string s;
int solve(int k)
{
    int temp=1;
    char c=s[0];
    int hold=1;
    int st=0,en=0;
    int j;
    for(j =1;j<n;j++)
    {
        if(s[j]==c)
        {
            temp++;
        }
        else
        {
            if(hold<temp)
            {
                hold=temp;
                en = j;
                st = j-hold;
            }
            c=s[j];
            temp=1;

        }
    }
    if(hold<temp){
            en=j;
    st=j-hold;
        hold=temp;}
    //cout<<s<<" "<<hold<<" "<<k<<" "<<st<<" "<<en<<endl;
    if(k<=0)
        return hold;
    for(int l = st;l<=en;l++)
    {
        s[l]=(s[l]=='0')?'1':'0';
        hold = min(hold,solve(k-1));
        s[l]=(s[l]=='0')?'1':'0';
    }
    return hold;


}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int k;
        cin>>n>>k;
        if(k>=n)
            k=n-1;
        cin>>s;
        cout<<solve(k)<<endl;
    }
    return 0;
}
