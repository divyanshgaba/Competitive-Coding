#include <iostream>
#include <cstring>
using namespace std;
char s[100];
int len;
int ans[52][52];
int answer(int st,int en)
{
    if(ans[st][en]!=0)
        return 0;
        //cout<<st<<" "<<en<<endl;

    ans[st][en]=1;
    if(st==en)
    {
        return 1;
    }
    int  i = st,j=en;
    int temp =1;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            temp=0;
            break;
        }
        i++;j--;
    }
    /*if(temp == 1)
    {
        for(int i =st;i<=en;i++)
            cout<<s[i];
        cout<<endl;
    }*/

    return temp + answer(st+1,en) + answer(st,en-1);
}


int main()
{
    cin>>s;
    len = strlen(s);
    cout<<answer(0,len-1);
    return 0;
}
