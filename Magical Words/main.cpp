#include <iostream>
#include <cstring>
using namespace std;
string s;
int len;
int ans[1002][1002];
long long answer(int st,int en)
{
    if(ans[st][en]!=0)
        return 0;
    ans[st][en]=1;
    if(st==en)
        return 1;
    int i =st,j = en;
    int temp = 1;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            temp =0;
            break;
        }
        i++;j--;
    }
    /*if(temp !=0)
    {
        for(int i =st;i<=en;i++)
            cout<<s[i];
        cout<<" "<<temp;
        cout<<endl;

    }*/
    if(temp!=0)
        temp=(en-st+1)*(en-st+1);
    return temp + answer(st+1,en)+answer(st,en-1);
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        memset(ans,0,sizeof(ans[0][0])*1002*1002);
        s="";
        cin>>s;
        len =s.length()-1;
        cout<<answer(0,len)<<endl;

    }
    return 0;
}
