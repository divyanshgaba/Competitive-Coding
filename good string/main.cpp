#include <iostream>
#include<cstdio>

using namespace std;

int main()
{
    int ch[27]={};
    for(char c = getchar();islower(c);c=getchar())
    {
        ch[c-'a']++;
    }
    int sum = 0;
    for(int i = 0;i<26;i++)
        {
            if(ch[i]<=1)
                continue;
            else
                sum= sum + ch[i]-1;
        }
        cout<<sum<<endl;
    return 0;
}
