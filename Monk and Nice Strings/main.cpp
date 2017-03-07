#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int a[1001];
int mystrcmp(string s,string temp)
{
    int len = min(s.length(),temp.length());
    for(int i = 0;i<len;i++)
    {
        if(s[i]==temp[i])
            continue;
        else if(s[i]> temp[i])
            return 1;
        else
            return 0;
    }
    if(s.length()> temp.length())
        return 1;
    return 0;
}
int main()
{
    int n;
    cin>>n;
    string temp[n];
    for(int i =0;i<n;i++)
    {
        cin>>temp[i];
    }
    for(int i =1;i<n;i++)
    {
        for(int j =0;j<i;j++)
        {
            a[i]+=mystrcmp(temp[i],temp[j]);
        }
    }
    for(int i =0;i<n;i++)
        cout<<a[i]<<endl;

    return 0;
}
