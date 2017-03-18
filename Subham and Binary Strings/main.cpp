#include <iostream>

using namespace std;


int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int z=0;
        for(int i =0;i<n;i++)
        {
            if(s[i]=='0')
                z++;
        }
        cout<<z<<endl;

    }
    return 0;
}
