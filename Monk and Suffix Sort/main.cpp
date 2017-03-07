#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string s;
    int n;
    cin>>s>>n;
    string hold = s;
    sort(hold.begin(),hold.end());
    char temp = hold[n-1];
    int count=0;
    //cout<<temp<<endl;
    for(int i =0;i<n-1;i++)
    {
        if(temp == hold[i])
            count++;
    }
    for(int i = 0;i<s.length();i++)
    {
        if(temp==s[i])
        {
            if(count==0)
            {
                count = i;
                break;
            }
            else
                count--;
        }

    }
    for(int i=count;i<s.length();i++)
        cout<<s[i];


    cout<<endl;
    return 0;
}
