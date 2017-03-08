#include <iostream>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        string s;
        cin>>s;
        int i,len =s.length();
        for( i =0;i<len/2;i++)
        {
            if(s[i] != s[len - i- 1])
                break;
        }
        if(i<len/2)
        {
            cout<<"NO"<<endl;

        }
        else
        {
            cout<<"YES ";
            if(len%2==0)
                cout<<"EVEN"<<endl;
            else
                cout<<"ODD"<<endl;
        }
    }
    return 0;
}
