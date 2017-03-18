#include <iostream>
#include <cstring>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        int n = s.length();
        for(int i =0;i<n;i++)
        {
            if(islower(s[i]))
               cout<<char(s[i]-32);
            else if(isupper(s[i]))
                cout<<char(s[i]+32);
            else
                cout<<s[i];

        }
        cout<<endl;
    }
    return 0;
}
