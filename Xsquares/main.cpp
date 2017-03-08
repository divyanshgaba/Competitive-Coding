#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        string s;

        cin>>s;
        int a[260];
        int i =0;
        memset(a,0,sizeof(int)*260);
        int len = s.length()+1;
        for(i =0;i<len;i++)
        {
            a[s[i]]++;
            //cout<<s[i]<<" ";
            if(a[s[i]]>1)
            {
                break;
            }
        }
        if(i<len)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
