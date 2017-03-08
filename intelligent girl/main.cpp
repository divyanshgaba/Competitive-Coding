#include <iostream>
#include <string>
using namespace std;
int val[10002];
int main()
{
    string s;
    cin>>s;
    int len = s.length();
    for(int i = len-1;i>=0;i--)
    {
        if((s[i]-'0')%2==0)
        {
            val[i] = val[i+1] +1;
        }
        else
            val[i] =val[i+1];
    }
    for(int i =0;i<len;i++)
        cout<<val[i]<<" ";
    cout<<endl;
    return 0;
}
