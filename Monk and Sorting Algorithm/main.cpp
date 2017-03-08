#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string.h>
using namespace std;
int strc(string s,string t)
{
    int slen= s.length();
    int tlen = t.length();
    if(slen> tlen)
        return 1;
    else if(slen<tlen)
        return 0;
    for(int i =0;i<slen;i++)
    {
        if(s[i] >t[i])
            return 1;
        else if(s[i]<t[i])
            return 0;
    }
    return 0;
}
int check;
string construct(string s,int from, int to)
{
    int n = s.length();
    char temp[abs(from - to +3)];
    memset(temp,'0',sizeof(temp));
    int k=0;
    for(int i = n-from;i<=n-to;i++)
    {
        if(i<0)
        {
            temp[k++]='0';
            continue;
        }
        check =1;
        temp[k++]=s[i];
    }
    temp[k]='\0';
    return temp;
}

int main()
{
    int n;
    cin>>n;
    string s[n];
    for(int i =0;i<n;i++)
        cin>>s[i];
    int i =1;
    while(true)
    {
        int from = 5*i;
        int to = 1 + 5*(i-1);
        string weight[n];
        check =0;
        for(int j =0;j<n;j++)
        {
            weight[j] = construct(s[j],from,to);
            //cout<<weight[j]<<endl;

        }
        if(check==0)
            break;
        for(int j =0;j<n;j++)
        {
            int flag =1;
            for(int k =0;k<n-1;k++)
            {
                if(strc(weight[k],weight[k+1]) == 1)
                {
                    swap(weight[k],weight[k+1]);
                    swap(s[k],s[k+1]);
                    flag =0;
                }
            }
            if(flag ==1)
                break;
        }
        for(int j =0;j<n;j++)
            cout<<s[j]<<" ";
        cout<<endl;
        i++;
    }

    return 0;
}
