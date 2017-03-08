#include <iostream>
#include <string>
#define red 'R'
#define blue 'B'
#define green 'G'

using namespace std;


int main()
{
    int test;
    cin>>test;
    while(test--){

        int n,countr=0,countb=0,countg=0,i,mini;
        cin>>n;
        string s;
        cin>>s;
        for(i=0;i<n;i++)
        {
            if(s[i]==red)
                continue;
            else
                countr++;

        }
        for(i=0;i<n;i++)
        {
            if(s[i]==green)
                continue;
            else
                countg++;

        }
         for(i=0;i<n;i++)
        {
            if(s[i]==blue)
                continue;
            else
                countb++;

        }
        mini=countb;
        if(mini>countr)
            mini=countr;
        if(mini>countg)
            mini=countg;
        cout<<mini<<endl;





        }






    return 0;
}
