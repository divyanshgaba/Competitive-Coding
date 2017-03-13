#include <iostream>

using namespace std;

int main()
{
    int t;
    string m;
    char k[28];
    cin>>t>>m;
    int len = m.length();
    for(int i =0;i < len;i++)
        k[i]=char(m[i]-'a' +'A');
    k[len]='\0';
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.length();
        for(int i =0;i<n;i++)
        {
            if(s[i]=='_')
                cout<<" ";
            else if(islower(s[i])||isupper(s[i]))
            {
                if(isupper(s[i]))
                    cout<<k[s[i]-'A'];
                else
                    cout<<m[s[i]-'a'];
            }
            else
                cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
