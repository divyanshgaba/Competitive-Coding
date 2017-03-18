#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int k;
        cin>>s>>k;
        int n = s.length();
        long long dec=0;
        for(int i =0;i<n;i++)
        {
            if(s[i]=='0'&&k!=0)
            {
                s[i]='1';
                k--;
            }
            if(s[i]=='1')
                dec+= pow(2,n-1-i);
        }
        cout<<dec<<endl;
    }
    return 0;
}
