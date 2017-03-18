#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    for(int i =0;i<s.length();i++)
    {
        if((i==0&&isalpha(s[i]))||(!isalpha(s[i-1])&&isalpha(s[i])))
        {
            if(i+2<s.length())
            {
                if(isdigit(s[i+1])&&isdigit(s[i+2]))
                {
                    if(i+3==s.length() || isalpha(s[i+3]))
                        s[i]=s[i+1]=s[i+2]='*';
                }
            }
        }
    }
    cout<<s;

    return 0;
}
